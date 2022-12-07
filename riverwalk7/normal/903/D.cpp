#include <iostream>
#include <fstream>
#include <map>
#define MAXN 200100
#define STO 1000000000000000000
typedef long long ll;
using namespace std;
ll a[MAXN];
ll power[19];
ll N;
map<ll, ll> m;
ll ans;
ll t;
int main()
{
    cin>>N;
    power[0] = 1;
    for(int i=1; i<=18; i++)
    {
        power[i] = power[i-1]*10;
    }
    for(int i=0; i<N; i++)
    {
        cin>>a[i];
        m[a[i]]++;
        ans += (a[i]*(2*i-N+1));
        ans += (m[a[i]+1]-m[a[i]-1]);
        if(ans >= STO)
        {
            ++t;
            ans -= STO;
        }
        if(ans <= -STO)
        {
            --t;
            ans += STO;
        }
    }
    if(t < 0 && ans > 0)
    {
        ++t;
        ans -= STO;
    }
    if(t > 0 && ans < 0)
    {
        --t;
        ans += STO;
    }
    if(t==0)
    {
        cout<<ans<<endl;
        return 0;
    }
    if(t<0)
    {
        ans = -ans;
    }
    cout<<t;
    for(int i=17; i>=0; i--)
    {
        cout<<(ans/power[i])%10;
    }
    cout<<""<<endl;
}