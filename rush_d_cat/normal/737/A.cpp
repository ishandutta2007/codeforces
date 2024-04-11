#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const ll NICO = 200002;
const ll INF = 2e9 + 7;
ll n, k, s, t;
ll p[NICO];
ll sum[NICO];
vector<int> dis;
ll min(ll x, ll y){return x<y?x:y;}
ll max(ll x, ll y){return x>y?x:y;}
struct Car
{
    ll c, v;
}car[NICO];
ll findpos(ll x)
{
    ll l = 0, r = dis.size()-1;
    if(dis[r]*2 < x) return -1;
    while(r - l > 1)
    {
        ll mid = (l+r) / 2;
        if(2 * dis[mid] >= x)
        {
            r = mid;
        } else {
            l = mid;
        }
    }
    if(r > 0 && dis[r-1]*2 >= x)
    {
        return r-1;
    }
    return r;
}
int main()
{
    cin >> n >> k >> s >> t;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld %lld", &car[i].v, &car[i].c);
    }
    p[0] = 0;sum[0] = 0;
    for(ll i=1;i<=k;i++)
    {
        scanf("%lld", &p[i]);
    }
    sort(p+1, p+1+k);
    for(ll i=1;i<=k;i++)
    {
        dis.push_back(p[i] - p[i-1]);
    }
    dis.push_back(s - p[k]);
    sort(dis.begin(), dis.end());
    for(int i=0;i<dis.size();i++)
    {
        sum[i+1]=sum[i]+dis[i];
    }
    ll ans = INF;
    for(ll i=1;i<=n;i++)
    {
        if(dis[dis.size()-1] > car[i].c) continue;
        ll pos = findpos(car[i].c);
        if(pos == -1)
        {
            if(sum[k+1] <= t)
            {
                ans = min(ans, car[i].v);
            }
            continue;
        }
        pos = pos + 1;
        ll tmp = sum[k+1] + 2 * (sum[k+1] - sum[max(pos-1, 0)]) - (k + 2 - pos) * (ll)car[i].c;
        if(tmp <= t) ans = min(ans, car[i].v);
    }

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}