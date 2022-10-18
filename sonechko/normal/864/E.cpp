#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2000 + 11;
int dp[N],t[N],d[N],p[N],num[N],tt[N],dd[N],pp[N];
pair<int,int> c[N];
vector<int> vv[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>tt[i]>>dd[i]>>pp[i];
    for (int i=1; i<=n; i++)
    {
        c[i]=mp(dd[i],i);
    }
    sort(c+1,c+n+1);
    for (int i=1; i<=n; i++)
    {
        t[i]=tt[c[i].ss];
        d[i]=dd[c[i].ss];
        p[i]=pp[c[i].ss];
        num[i]=c[i].ss;
    }
    for (int i=1; i<=n; i++)
    for (int j=d[i]; j>=1; j--)
    if (j>t[i])
    {
        if (dp[j]<dp[j-t[i]]+p[i])
        {
        vv[j]=vv[j-t[i]];
        vv[j].pb(num[i]);
        dp[j]=dp[j-t[i]]+p[i];
        }
    }
    int ans=0;
    for (int i=1; i<=2000; i++)
        if (dp[i]>dp[ans]) ans=i;
    cout<<dp[ans]<<endl;
    cout<<vv[ans].size()<<endl;
    for (int i=0; i<vv[ans].size(); i++)
        cout<<vv[ans][i]<<" ";
    cout<<endl;
}