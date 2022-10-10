#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;
vector<int> pos[MAXN];
int n, m, eve[MAXN], swp[MAXN], ri[MAXN], idx[MAXN];
array<int, 4> req[MAXN];

void mark(int l, int r) {
    l = max(l, 0);
    swp[l]++;
    swp[r + 1]--;
}

bool check(int l) {
    for(int i = 0; i <= n; i++)
        swp[i] = 0;
    for(int i = 0; i < n; i++) {
        auto [l1, r1, l2, r2] = req[i];
        if(l1 == -1) {
            mark(0, n - 1);
            continue;
        }
        if(r1 - l + 1 > l1 && r2 - l + 1 > l2)
            return false;
        if(min(l1, l2) >= max(r1 - l + 1, r2 - l + 1)) {
            mark(min(r1 - l + 1, r2 - l + 1), max(l1, l2));
            continue;
        }
        if(r1 - l + 1 <= l1)
            mark(r1 - l + 1, l1);
        if(r2 - l + 1 <= l2)
            mark(r2 - l + 1, l2);
    }
    int cur = 0;
    for(int i = 0; i < n; i++) {
        cur += swp[i];
        if(cur == n)
            return true;
    }
    return false;
}

void solve() {
    cin >> n >> m;

    for(int i = 0; i <= n; i++) {
        pos[i].clear();
        eve[i] = -1;
        req[i] = {-1, -1, -1, -1};
    }

    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    vector<int> sv = v;
    sort(sv.begin(), sv.end());
    sv.erase(unique(sv.begin(), sv.end()), sv.end());
    map<int, int> conv;
    for(int i = 0; i < sv.size(); i++)
        conv[sv[i]] = i;
    for(auto &x : v)
        x = conv[x];

    //for(auto &x : v)
    //    cout << x << " ";
    //cout << '\n';

    vector<array<int, 2>> segs(m);
    for(auto &[l, r] : segs) {
        cin >> l >> r;
        eve[l - 1] = max(eve[l - 1], r - 1);
    }
    int cur = -1;
    for(int i = 0; i < n; i++) {
        cur = max(cur, eve[i]);
        ri[i] = cur;
    }

    //for(int i = 0; i < n; i++)
    //    cout << ri[i] << " ";
    //cout << '\n';

    for(int i = 0; i < n; i++) {
        idx[i] = pos[v[i]].size();
        pos[v[i]].push_back(i);
    }

    for(int i = 0; i < n; i++) {
        if(ri[i] < i)
            continue;
        int a = v[i];
        int lo = 0, hi = pos[a].size() - 1;
        while(lo < hi) {
            int mi = (lo + hi + 1)/2;
            if(pos[a][mi] <= ri[i])
                lo = mi;
            else
                hi = mi - 1;
        }
        int i1 = idx[i], i2 = lo;
        if(i1 == i2)
            continue;
        req[i] = {pos[a][i1], pos[a][i2 - 1], pos[a][i1 + 1], pos[a][i2]};
    }

    int lo = 0, hi = n;
    while(lo < hi) {
        int mi = (lo + hi)/2;
        if(check(mi))
            hi = mi;
        else
            lo = mi + 1;
    }

    cout << lo << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}