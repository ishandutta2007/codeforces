#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 200 + 11;

int dp[N][N][N];
pair<pair<int,int>,pair<int,int> > pr[N][N][N];
vector<pair<int,pair<int,int> > > vv;
int n,m;

void up(int l, int r, int k, int ans, int c1, int c2, int c3, int c4)
{
    if (k<0||k>max(n,m)) return;
    if (dp[l][r][k]!=-1) return;
    dp[l][r][k]=ans;
    pr[l][r][k]=mp(mp(c1,c2),mp(c3,c4));
    ///cout<<l<<" "<<r<<" "<<k<<" "<<ans<<endl;
    vv.pb(mp(l,mp(r,k)));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s,t;
    cin>>s>>t;
    n=s.size();
    m=t.size();
    s="."+s;
    t="."+t;
    for (int i=0; i<=n; i++)
    for (int j=0; j<=m; j++)
    for (int bal=0; bal<=max(n,m); bal++)
        dp[i][j][bal]=-1;
    dp[0][0][0]=0;
    vv.pb(mp(0,mp(0,0)));
    for (int j=0; j<vv.size(); j++)
    {
        int l=vv[j].ff;
        int r=vv[j].ss.ff;
        int k=vv[j].ss.ss;
        int ans=dp[l][r][k]+1;
        up(l,r,k+1,ans,1,l,r,k);
        up(l,r,k-1,ans,-1,l,r,k);
        if (l<n&&r<m&&s[l+1]=='('&&t[r+1]=='(') up(l+1,r+1,k+1,ans,1,l,r,k);
        if (l<n&&r<m&&s[l+1]==')'&&t[r+1]==')') up(l+1,r+1,k-1,ans,-1,l,r,k);
        if (l<n&&s[l+1]=='(') up(l+1,r,k+1,ans,1,l,r,k);
        if (l<n&&s[l+1]==')') up(l+1,r,k-1,ans,-1,l,r,k);
        if (r<m&&t[r+1]=='(') up(l,r+1,k+1,ans,1,l,r,k);
        if (r<m&&t[r+1]==')') up(l,r+1,k-1,ans,-1,l,r,k);
    }
    string ans="";
    int k=0;
    while (n!=0||m!=0||k!=0)
    {
        pair<pair<int,int>,pair<int,int> > p=pr[n][m][k];
        if (p.ff.ff==1) ans+="("; else ans+=")";
        n=p.ff.ss;
        m=p.ss.ff;
        k=p.ss.ss;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}