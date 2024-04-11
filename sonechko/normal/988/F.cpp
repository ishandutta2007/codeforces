#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;

bool use[N];
pair<int,int> a[N];
int dp[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k,m;
    cin>>n>>k>>m;
    for (int i=1; i<=k; i++)
    {
        int l,r;
        cin>>l>>r;
        for (int j=l; j<r; j++)
            use[j]=1;
    }
    for (int i=1; i<=m; i++)
        cin>>a[i].ff>>a[i].ss;
    sort(a+1,a+m+1);
    for (int j=n; j>=0; j--)
        dp[j]=-1;
    for (int j=n; j>=0; j--)
    {
        if (use[j]) break;
        dp[j]=0;
    }
    for (int j=m; j>=1; j--)
    {
        int l=a[j].ff,cost=a[j].ss;
        for (int p=l; p<=n; p++)
            if (dp[p]!=-1)
        {
            int xx=dp[p]+(p-l)*cost;
            if (dp[l]==-1||dp[l]>xx) dp[l]=xx;
        }
        int dd=0;
        for (int p=n; p>=0; p--)
        {
            if (use[p]) dd=dp[p]; else
            if (dp[p]!=-1&&(dd==-1||dd>dp[p])) dd=dp[p];
            if (dd!=-1&&(dp[p]==-1||dp[p]>dd)) dp[p]=dd;
        }
    }
    cout<<dp[0]<<endl;
}