#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 2e5 + 10;
int a[MAXN], b[MAXN], amin[MAXN], bmin[MAXN];
int n, m, k, s;
ii costs[MAXN];

bool check(int en) {
    ll dprice = amin[en], pprice = bmin[en];
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for(int i = 1; i <= m; i++) {
        ll pri = (costs[i].first == 1 ? dprice * costs[i].second : pprice * costs[i].second);
        q.push(pri);
    }
    ll tot = 0;
    for(int i = 0; i < k; i++) {
        ll a = q.top(); q.pop();
        tot += a;
        if(tot > (ll)s)
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k >> s;
    amin[0] = bmin[0] = INT_MAX;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    for(int i = 1; i <= n; i++) {
        amin[i] = min(amin[i - 1], a[i]);
        bmin[i] = min(bmin[i - 1], b[i]);
    }
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        costs[i] = {x, y};
    }
    if(!check(n)) {
        cout << "-1\n";
        return 0;
    }
    int lo = 1, hi = n;
    while(lo < hi) {
        int mi = (lo + hi)/2;
        if(check(mi))
            hi = mi;
        else
            lo = mi + 1;
    }
    cout << lo << '\n';
    ll dpri = amin[lo], ppri = bmin[lo];
    int dpos, ppos;
    for(int i = 1; i <= lo; i++) {
        if(a[i] == dpri)
            dpos = i;
        if(b[i] == ppri)
            ppos = i;
    }
    priority_queue<ii> Q;
    for(int i = 1; i <= m; i++) {
        ll pri = (costs[i].first == 1 ? dpri * costs[i].second : ppri * costs[i].second);
        Q.push({-pri, i});
    }
    for(int i = 0; i < k; i++) {
        auto p = Q.top(); Q.pop();
        int idx = p.second;
        if(costs[idx].first == 1)
            cout << idx << " " << dpos << '\n';
        else
            cout << idx << " " << ppos << '\n';
    }
}