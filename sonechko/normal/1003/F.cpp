#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 998244353;
const int P = 31;
const int D = 10387593;
int st1[N],st2[N];
int a[500],dp[500][500];
int d[500],sum[500][500];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    st1[0]=P;
    st2[0]=D;
    for (int j=1; j<=1000000; j++)
    {
        st1[j]=(st1[j-1]*1ll*P)%MOD;
        st2[j]=(st2[j-1]*1ll*D)%MOD;
    }
    int ans=n-1,t=n-1;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        d[i]=s.size();
        ll h=0;
        for (int j=0; j<s.size(); j++)
            h=(h+(s[j]-'a'+1)*1ll*st1[j])%MOD;
        a[i]=h;
        ans+=s.size();
        t+=s.size();
    }
    for (int i=1; i<=n; i++)
    {
        ll h=0;
        ll s=0;
        for (int j=i; j<=n; j++)
        {
            h=(h+a[j]*1ll*st2[j-i])%MOD;
            dp[i][j-i+1]=h;
            s+=d[j];
            sum[i][j-i+1]=s;
        }
    }
    for (int i=1; i<=n; i++)
    for (int len=1; len<=n-i+1; len++)
    {
        int kol=0,pos=0;
        for (int j=1; j<=n; j++)
            if (dp[i][len]==dp[j][len]&&j>pos)
        {
            kol++;
            pos=j+len-1;
        }
        //cout<<i<<" "<<len<<" - "<<kol<<" -- "<<t-kol*(sum[i][len]-len)<<endl;
        if (kol>1) ans=min(ans,t-kol*(sum[i][len]-len)-kol*(len-1));
    }
    cout<<ans<<endl;
}