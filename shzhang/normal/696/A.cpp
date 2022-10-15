#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>

using namespace std;

char s[5005];

#define ll long long

typedef int I;
#define rep(var, to) for (I var = 1; var <= (to); var++)
#define repv(vec, var) for (I var = 0; var < (vec).size(); var++)
#define repf(var, from, to) for (I var = (from); var <= (to); var++)
#define repd(var, from, to) for (I var = (from); var >= (to); var--)

map<ll, ll> cost;

ll getcost(ll edge)
{
    if (cost.count(edge)) return cost[edge];
    return 0;
}

void addcost(ll edge, ll val)
{
    if (cost.count(edge)) cost[edge] += val;
    else cost[edge] = val;
}

int log_2(ll val)
{
    for (int i = 62; i >= 0; i--) {
        if (val & (1LL << (ll)i)) return i;
    }
    return 0;
}

vector<ll> path(ll u, ll v)
{
    vector<ll> ans;
    if (u < v) {
        ll t = u; u = v; v = t;
    }
    int cnt = log_2(u) - log_2(v);
    for (int i = 1; i <= cnt; i++) {
        ans.push_back(u); u >>= 1;
    }
    while (u != v) {
        ans.push_back(u); ans.push_back(v);
        u >>= 1; v >>= 1;
    }
    return ans;
}

int main()
{
    int q;
    scanf("%d", &q);
    for (int qry = 1; qry <= q; qry++) {
        int type; ll u, v;
        scanf("%d%lld%lld", &type, &u, &v);
        vector<ll> p = path(u, v);
        if (type == 1) {
            ll w;
            scanf("%lld", &w);
            for (int i = 0; i < p.size(); i++) {
                addcost(p[i], w);
            }
        } else {
            ll ans = 0;
            for (int i = 0; i < p.size(); i++) {
                ans += getcost(p[i]);
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}