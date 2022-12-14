#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long
map<pair<ll,ll>,ll>m;
ll solve (ll x)
{
    ll l =0 ;
    while(x!=0)
    {
        l++;
        x/=10;
    }
    return l ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k, mx =0;
    cin >>n>>k;
    ll a[n];
    for (int i =0 ; i <n ; i++)
    {
        cin >>a[i];
        pair<ll,ll>p;
        p.first = a[i]%k;
        p.second = solve (a[i]);
        mx = max (mx, solve (a[i]));
        m[p]++;
    }
    ll sum=0 ;
    for (int i = 0 ; i <n ; i++)
    {
        ll r = mx ;
        ll t = a[i];
        ll j =1;
        while (r != 0 )
        {
            t*=10;
            r--;


            ll d = k-(t%k);
            d=d%k;
            if (m.find(make_pair(d,j))!=m.end())
            {
                if (solve(a[i])==j && d==a[i]%k)
                    sum+=(m[make_pair(d,j)]-1);
                else
                    sum+=m[make_pair(d,j)];
            }
            j++;
        }

    }
    cout <<sum <<endl;




    return 0;
}