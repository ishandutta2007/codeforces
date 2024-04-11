#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
ll NUM = 1000000007;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

int main()
{
    ll s,b;
    cin>>s>>b;
    vp64 pwr(s);
    vp64 bss(b);
    vp64 output(s);
    forn(i, s)
    {
        cin>>pwr[i].ff;
        pwr[i].ss = i;
    }
    sort(pwr.begin(), pwr.end());
    forn(i, b)
    {
        cin>>bss[i].ff;
        cin>>bss[i].ss;
    }
    sort(bss.begin(), bss.end());
    ll sum = 0, cnt = 0;
    forn(i, s)
    {
        while(cnt < b && bss[cnt].ff <= pwr[i].ff)
        {
            sum += bss[cnt].ss;
            cnt++;
        }
        output[i].ff = pwr[i].ss;
        output[i].ss = sum;
    }
    sort(output.begin(), output.end());
    forn(i,s)
    {
        cout<<output[i].ss<<" ";
    }
    return 0;
}