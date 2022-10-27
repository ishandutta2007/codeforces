#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef __int64 ll;
ll min(ll x, ll y)
{
    return x < y? x : y;
}
int main()
{
    ll d,k,a,b,t;
    cin>>d>>k>>a>>b>>t;
    if(d<=k)
    {
        cout<< (d*a) <<endl;
    } else {
        ll res = 0;
        res += k * a;
        if(k * a + t >= k * b)
        {
            res += b * (d - k);
            cout << res <<endl;
        } else {
            res += ((d - k) / k) * (k * a + t);
            ll last = (d - k) % k;
            res += min(b * last, t + a * last);
            cout<< res <<endl;
        }
    }
}