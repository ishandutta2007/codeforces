#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3000 + 11;
const ll MOD = 998244353;

ll dp1[N][N],dp2[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    string t;
    cin>>s>>t;
    s="."+s;
    t="."+t;
    int n=s.size()-1;
    int m=t.size()-1;
    for (int i=1; i<=m+1; i++)
        dp1[i][i-1]=1;
    for (int len=0; len<m; len++)
    for (int l=1; l<=m+1; l++)
    {
        int r=l+len-1;
        if (l==m+1&&len!=0) continue;
        if (l>1&&s[len+1]==t[l-1])
        {
            dp1[l-1][r]=(dp1[l-1][r]+dp1[l][r])%MOD;
        }
        if (r<m&&s[len+1]==t[r+1])
        {
            dp1[l][r+1]=(dp1[l][r+1]+dp1[l][r])%MOD;
        }
    }
    dp2[n+1][0]=1;
    for (int i=n; i>=1; i--)
    for (int k=0; k<=min(m,n-i+1); k++)
    {
        if (k==0) dp2[i][k]=(dp2[i][k]+dp2[i+1][k]+1)%MOD; else
            dp2[i][k]=(dp2[i][k]+dp2[i+1][k])%MOD;
        if (k+1<=m&&s[i]==t[k+1])
            dp2[i][k+1]=(dp2[i][k+1]+dp2[i+1][k])%MOD;
    }
    ll ans=0;
    ll ts=1;
    for (int k=1; k<=n-m; k++)
    {
        ts*=2ll;
        ts%=MOD;
        ll kol=(dp2[k+1][m]-dp2[k+2][m]+MOD)%MOD;
        ///cout<<k<<": "<<ts<<"*"<<kol<<endl;
        ans=(ans+ts*1ll*kol)%MOD;
    }
    for (int ks=m; ks>=1; ks--)
    {
        ///cout<<ks<<".."<<m<<endl;
        ll kol1=dp1[ks][m];
        ll kol2=dp2[(m-ks+1)+2][ks-1];
        if (ks==1) kol2++;
        ans=(ans+kol1*1ll*kol2)%MOD;
    }
    cout<<ans;
}
/**
          .

**/