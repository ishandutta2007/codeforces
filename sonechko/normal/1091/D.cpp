#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e6 + 11;
const int MOD = 998244353;

ll use[N];
vector<ll> v1,v2;
ll n,p,ans,fac[N],ob[N];

void rec(int l)
{
    if (l==n+1)
    {
        if ((int)v1.size()==0) {} else
        {
            for (int p=0; p<v1.size(); p++)
                if (v1[p]!=v2[p]) break; else ans++;
        }
        v1=v2;
        return;
    }
    for (int j=1; j<=n; j++)
        if (use[j]==0)
    {
        use[j]=1;
        v2.pb(j);
        rec(l+1);
        use[j]=0;
        v2.pop_back();
    }
}

ll step(ll x, ll y)
{
    if (y==0) return 1;
    if (y%2==1) return (x*step(x,y-1))%MOD;
    ll c=step(x,y/2);
    return (c*c)%MOD;
}

ll cnk(ll n, ll k)
{
    ll ans=fac[n];
    ans=(ans*ob[k])%MOD;
    ans=(ans*ob[n-k])%MOD;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    //rec(1);
    /**
    int ans=0;
    for (int i=1; i<=kol; i++)
    {
        ll t=0;
        for (int j=i; j<=kol; j++)
        {
            t+=a[j];
            if (j-i+1==n&&t==n*(n+1)/2)
            {
                ans++;
            }
        }
    }
    **/
    fac[0]=1;
    ob[0]=1;
    for (int i=1; i<=n; i++)
    {
        fac[i]=(fac[i-1]*1ll*i)%MOD;
        ob[i]=step(fac[i],MOD-2);
    }
    for (int len=0; len<n; len++)
    {
        ll d1=(fac[len]*cnk(n,len))%MOD;
        ll d2=cnk(n-len,1);
        ll d3=fac[n-len-1]-1;
        d2=(d2*d3)%MOD;
        ans=(ans+d1*d2)%MOD;
    }
    cout<<(ans+fac[n])%MOD<<endl;
}
/**
1 - 0 - 1
2 - 0 - 2
3 - 3 - 9
4 - 32 - 56
5 - 275 - 395
6 - 2364 - 3084
**/