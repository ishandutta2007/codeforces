#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
const int MAXT = 1e6 + 5;
const ll INF = 1e18;
ll wt[MAXN], coo[MAXN], ans[MAXN], T;
int n;
vector <pair<int, ll>> adj[MAXN];

struct fenwick {
    ll BIT[MAXT];
    fenwick() { memset(BIT, 0, sizeof BIT); }

    void upd(ll p, ll v) {
        for(;p < MAXT; p += (p & -p))
            BIT[p] += v;
    }

    ll sum(ll p) {
        ll res = 0;
        for(;p > 0; p -= (p & -p))
            res += BIT[p];
        return res;
    }

    ll mxbefore(ll bnd) {
        int pos = 0;
        for(int ex = (1 << 20); ex > 0; ex >>= 1) {
            if(pos + ex < MAXT && BIT[pos + ex] <= bnd)
                pos += ex, bnd -= BIT[pos];
        }
        return pos;
    }
};

fenwick tot, yum;

ll solve(int s, ll time = 0) {
    ans[s] = 0;
    tot.upd(wt[s], wt[s]*coo[s]);
    yum.upd(wt[s], coo[s]);
    if(2*time > T)
        ans[s] = -INF;
    else {
        // End in current vertex
        ll rem = T - 2*time, amt = 0;
        ll sf = tot.mxbefore(rem);
        amt += yum.sum(sf);
        if(rem < tot.sum(MAXT - 1)) {
            rem -= tot.sum(sf);
            amt += rem/(sf + 1ll);
        }
        ans[s] = amt;
    }
    ll mx = -INF;
    for(auto e : adj[s]) {
        solve(e.first, time + e.second);
        mx = max(mx, ans[e.first]);
    }
    bool smx = false;
    if(s == 1)
        smx = true;
    for(auto e : adj[s]) {
        if(ans[e.first] == mx && !smx)
            smx = true;
        else
            ans[s] = max(ans[s], ans[e.first]);
    }
    tot.upd(wt[s], -wt[s]*coo[s]);
    yum.upd(wt[s], -coo[s]);
    return ans[s];
}

int main() {
    cin >> n >> T;
    for(int i = 1; i <= n; i++)
        cin >> coo[i];
    for(int i = 1; i <= n; i++)
        cin >> wt[i];
    for(int i = 2; i <= n; i++) {
        int u;
        ll w;
        cin >> u >> w;
        adj[u].push_back({i, w});
    }
    cout << solve(1) << endl;
}