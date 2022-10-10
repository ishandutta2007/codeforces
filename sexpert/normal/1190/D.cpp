#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 2e5 + 10;
int BIT[MAXN], xs[MAXN];
vector<int> by_y[MAXN];

ll sum(int p) {
    ll res = 0;
    for(; p > 0; p -= (p & -p)) res += BIT[p];
    return res;
}

void upd(int p, ll v) {
    for(; p < MAXN; p += (p & -p)) BIT[p] += v;
}

inline ll pairs(ll n) { return n*(n + 1)/2; }
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int cur = 2;
    map<int, int> mx, my;

    int n;
    cin >> n;
    vector<ii> v(n);
    for(int i = 0 ; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
        mx[x] = my[y] = 0;
    }
    for(auto p : mx) mx[p.first] = cur++;
    cur = 2;
    for(auto p : my) my[p.first] = cur++;

    for(auto &p : v) {
        p = {mx[p.first], my[p.second]};
        by_y[p.second].push_back(p.first);
    }

    ll ans = 0;
    for(int h = cur - 1; h >= 2; h--) {
        for(auto x : by_y[h])
            if(!xs[x]) { xs[x] = 1; upd(x, 1); }
        sort(by_y[h].begin(), by_y[h].end());
        ll tot = pairs(sum(n + 1));
        tot -= pairs(sum(by_y[h][0] - 1));
        tot -= pairs(sum(n + 1) - sum(by_y[h][by_y[h].size() - 1]));
        for(int i = 1; i < by_y[h].size(); i++)
            tot -= pairs(sum(by_y[h][i] - 1) - sum(by_y[h][i - 1]));
        ans += tot;
    }
    cout << ans << '\n';
}