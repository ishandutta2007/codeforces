#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
const ll MOD = 1e9 + 7;
#define mod %MOD

const ll N = 1e5 + 11;

int dp[72][600000];
int kol[72];
int ks1[72],ks2[72],fac[N];
int mm[72];
int xx[72];
void fact()
{
    fac[0]=1;
    fac[1]=1;
    for (ll i=2; i<=100000; i++)
        fac[i]=(fac[i-1]*1LL*i)mod;
}
ll powx(ll p, ll d)
{
    if (d==0) return 1;
    if (d%2==1) return (powx(p,d-1)*1LL*p)mod;
    ll pp=powx(p,d/2);
    return (pp*1LL*pp)mod;
}
ll cnk(ll n, ll k)
{
    ll res=fac[n];
    res=(res*1LL*powx(fac[k],MOD-2))mod;
    res=(res*1LL*powx(fac[n-k],MOD-2))mod;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    for (ll i=1; i<=n; i++)
    {
        ll l;
        cin>>l;
        kol[l]++;
    }
    xx[1]=2;xx[2]=3;xx[3]=5;xx[4]=7;xx[5]=11;xx[6]=13;xx[7]=17;xx[8]=19;
    xx[9]=23;xx[10]=29;xx[11]=31;xx[12]=37;xx[13]=41;xx[14]=43;xx[15]=47;
    xx[16]=53;xx[17]=59;xx[18]=61;xx[19]=67;

    fact();
    for (ll i=1; i<=70; i++)
    {
        for (ll j=1; j<=kol[i]; j+=2)
            ks1[i]=(ks1[i]+cnk(kol[i],j))mod;
        for (ll j=0; j<=kol[i]; j+=2)
            ks2[i]=(ks2[i]+cnk(kol[i],j))mod;
        ll p=i;
        for (ll j=1; j<=19; j++)
        {
            ll dd=0;
            while (p%xx[j]==0)
            {
                p/=xx[j];
                dd^=1;
            }
            if (dd==1) mm[i]^=(1<<(j-1));
        }
    }
    dp[0][0]=1;
    ll pp=(1<<19)-1;
    for (ll i=1; i<=70; i++)
    {
        for (ll j=0; j<=pp; j++)
        {
            ll mask=j;
            dp[i][j]+=(dp[i-1][j]*1LL*ks2[i])mod;
            dp[i][j]%=MOD;
            mask^=mm[i];
            dp[i][j]+=(dp[i-1][mask]*1LL*ks1[i])mod;
            dp[i][j]%=MOD;
        }
    }
    cout<<(dp[70][0]-1+MOD)mod<<endl;
}