#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
const ll MOD = 1e9 + 7;
#define mod %MOD

const ll N = 1e6 + 11;
int kol[N];
int fac[N];
void fact()
{
    fac[0]=1;
    fac[1]=1;
    for (ll i=2; i<=1000000; i++)
        fac[i]=(fac[i-1]*1LL*i)mod;
}
int powx(int p, int d)
{
    if (d==0) return 1;
    if (d%2==1) return (powx(p,d-1)*1LL*p)mod;
    int pp=powx(p,d/2);
    return (pp*1LL*pp)mod;
}
int mn(int l, int r)
{
    return (l*1LL*r)mod;
}
int dil(int l, int r)
{
    return (l*1LL*powx(r,MOD-2))mod;
}
int f(string a, string b)
{
    for (int j=0; j<=26; j++)
    kol[j]=0;
    for (int j=0; j<a.size(); j++)
        kol[a[j]-'a']++;
    int d=a.size();
    int res=fac[d];
    for (int j=0; j<26; j++)
        res=dil(res,fac[kol[j]]);
    int ans=0;
    for (int j=0; j<b.size(); j++)
    {
        res=dil(res,d);
        d--;
        for (int p=b[j]-'a'-1; p>=0; p--)
            if (kol[p]>0)
        {
            int pres=mn(res,kol[p]);
            ans=(ans+pres)mod;
        }
        int dd=b[j]-'a';
        if (kol[dd]==0) break;
        res=mn(res,kol[dd]);
        kol[dd]--;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s,t;
    cin>>s>>t;
    fact();
    cout<<(1LL*f(s,t)-1LL*f(s,s)-1LL+1LL*MOD+1LL*MOD)mod<<endl;
}