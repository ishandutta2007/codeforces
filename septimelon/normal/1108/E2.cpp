#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000000009;

vector<int> v;
vector<int> vd;
vector<int> ma;
vector<int> mi;

void ass(int x, int val, int l, int r, int c) {
    if (r == l + 1) {
        v[c] = val;
        ma[c] = val;
        mi[c] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (x < mid) {
        ass(x, val, l, mid, c * 2 + 1);
    } else {
        ass(x, val, mid, r, c * 2 + 2);
    }
    ma[c] = max(ma[c * 2 + 1], ma[c * 2 + 2]);
    mi[c] = min(mi[c * 2 + 1], mi[c * 2 + 2]);
}

void dif(int dv, int cl, int cr, int l, int r, int c) {
    cl = max(cl, l);
    cr = min(cr, r);
    if (l == cl && r == cr) {
        vd[c] += dv;
    }
    if (cl >= r || cr <= l || cr <= cl) {
        return;
    }
    if (r - l > 1) {
        vd[c * 2 + 1] += vd[c];
        vd[c * 2 + 2] += vd[c];
        vd[c] = 0;
        int mid = (l + r) / 2;
        if (l != cl || r != cr) {
            dif(dv, cl, cr, l, mid, c * 2 + 1);
            dif(dv, cl, cr, mid, r, c * 2 + 2);
        }
        ma[c] = max(ma[c * 2 + 1] + vd[c * 2 + 1], ma[c * 2 + 2] + vd[c * 2 + 2]);
        mi[c] = min(mi[c * 2 + 1] + vd[c * 2 + 1], mi[c * 2 + 2] + vd[c * 2 + 2]);
    }
    if (r - l == 1) {
        v[c] += vd[c];
        vd[c] = 0;
        ma[c] = v[c];
        mi[c] = v[c];
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> l(m), r(m);
    vector<pair<int, int>> lr, rl;
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i];
        --l[i];
        lr.push_back({l[i], r[i]});
        rl.push_back({r[i], l[i]});
    }
    sort(lr.begin(), lr.end());
    sort(rl.begin(), rl.end());
    
    v.assign(n * 4 + 5, 0);
    vd.assign(n * 4 + 5, 0);
    ma.assign(n * 4 + 5, 0);
    mi.assign(n * 4 + 5, 0);
    
    for (int i = 0; i < n; ++i) {
        ass(i, a[i], 0, n, 0);
    }
    
    for (int i = 0; i < m; ++i) {
        dif(-1, l[i], r[i], 0, n, 0);
    }
    
    int lri = 0;
    int rli = 0;
    int md = -1;
    int tm = -1;
    for (int cm = 0; cm < n; ++cm) {
        while (lri < m && lr[lri].first == cm) {
            dif(1, lr[lri].first, lr[lri].second, 0, n, 0);
            ++lri;
        }
        while (rli < m && rl[rli].first == cm) {
            dif(-1, rl[rli].second, rl[rli].first, 0, n, 0);
            ++rli;
        }
        //cout << cm << ": " << ma[0] - mi[0] << "\n";
        if (ma[0] - mi[0] > md) {
            md = ma[0] - mi[0];
            tm = cm;
        }
    }
    
    cout << md << "\n";
    vector<int> os;
    for (int i = 0; i < m; ++i) {
        if (l[i] > tm || r[i] <= tm) {
            os.push_back(i + 1);
        }
    }
    cout << os.size() << "\n";
    for (int i = 0; i < os.size(); ++i) {
        cout << os[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    for (int qq = 0; qq < t; ++qq) {
       solve();
    }
   
    return 0;
}