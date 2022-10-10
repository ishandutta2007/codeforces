#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10;
int rep[MAXN], le[MAXN], ri[MAXN], a[MAXN], pp[MAXN], ans[MAXN], bad[MAXN];
vector<int> all[MAXN];

int find(int u) {
    return rep[u] == u ? u : rep[u] = find(rep[u]);
}

void join(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v)
        return;
    le[u] = min(le[u], le[v]);
    ri[u] = max(ri[u], ri[v]);
    rep[v] = u;
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        all[i].clear();
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        all[a[i]].push_back(i);
        pp[i] = 0;
        rep[i] = le[i] = ri[i] = i;
        ans[i] = 1;
        bad[i] = 0;
    }
    for(int cur = n; cur >= 1; cur--) {
        int mx = 0;
        for(auto p : all[cur]) {
            if(p > 0 && a[p - 1] >= cur)
                join(p - 1, p);
            if(p < n && a[p + 1] >= cur)
                join(p, p + 1);
            int u = find(p);
            mx = max(mx, ri[u] - le[u] + 1);
        }
        if(mx) {
            pp[mx]++;
            int ect = n - cur + 1;
            //cout << cur << " " << mx << endl;
            if(mx > ect) {
                bad[ect + 1]++;
                bad[mx + 1]--;
            }
        }
    }
    int cur = 0;
    for(int i = n; i >= 1; i--) {
        pp[i] += cur;
        cur = pp[i];
    }
    cur = 0;
    for(int i = 1; i <= n; i++) {
        cur += bad[i];
        if(cur || pp[i] != n - i + 1)
            ans[i] = 0;
        cout << ans[i];
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();    
}