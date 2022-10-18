#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define ss second

const int N = 5e5 + 11;
const int MOD = 1e9 + 7;
const int P = 29;

int n;
ll h[N];
ll st[N];

bool good(int l, int r, int len)
{
    ll h1=(h[r+len-1]-h[r-1]+MOD)%MOD;
    h1=(h1*st[n-r])%MOD;
    ll h2=(h[l+len-1]-h[l-1]+MOD)%MOD;
    h2=(h2*st[n-l])%MOD;
    return (h1==h2);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int k1=0,k0=0;
    for (int j=0; j<s.size(); j++)
        if (s[j]=='1') k1++; else k0++;
    cin>>s;
    n=s.size();
    s="."+s;
    int kk1=0,kk0=0,kkk1=0,kkk0=0;
    for (int i=1; i<=n; i++)
        if (s[i]=='1') kk1++; else kk0++;
    st[0]=1;
    for (int i=1; i<=n; i++)
        st[i]=(st[i-1]*1ll*P)%MOD;
    for (int i=1; i<=n; i++)
        h[i]=(h[i-1]+st[i]*(s[i]-'0'+1))%MOD;
    int t=0;
    for (int i=2; i<=n; i++)
        if (good(1,i,n-i+1)) {t=n-i+1; break;}
    for (int i=t+1; i<=n; i++)
        if (s[i]=='1') kkk1++; else kkk0++;
    string ans="",s1="",s2="";
    for (int i=t+1; i<=n; i++)
        s2+=s[i];
    for (int i=1; i<=n; i++)
        s1+=s[i];
    if (k1>=kk1&&k0>=kk0)
    {
        k1-=kk1;
        k0-=kk0;
        ans+=s1;
    }
    while (k1>=kkk1&&k0>=kkk0)
    {
        k1-=kkk1;
        k0-=kkk0;
        ans+=s2;
    }
    while (k0--)
    ans+="0";
    while (k1--)
    ans+="1";
    cout<<ans<<endl;
}