#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef __int64 ll;
const ll inf = 2000000000;
ll a[400000+2];
ll b[400000+2];
ll max(ll x,ll y){return x>y?x:y;}
ll min(ll x,ll y){return x<y?x:y;}
int main()
{
    ll n, m, i, res = 0, l = 1, r = 1;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(i = 1; i <= m; i++)
    {
        cin >> b[i];
    }

    for(i = 1; i <= n; i++)
    {
        if(a[i] <= b[1])
        {
            res = max(res, b[1] - a[i]);
            continue;
        }
        if(a[i] >= b[m])
        {
            res = max(res, a[i] - b[m]);
            continue;
        }
        int pos = lower_bound(b + 1, b + 1 + m, a[i]) - b;//tower

        if(pos != 1)
            res = max(res, min(b[pos] - a[i], a[i] - b[pos - 1]));
        else
            res = max(res, b[pos] - a[i]);
    }
    cout <<res<<endl;

    return 0;
}