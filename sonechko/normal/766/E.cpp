#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

const int N = 1e5 + 11;

ll dp[2][N],res,ans;
int a[N];
vector<int> v[N];

void dfs(int l, int pr, int kk)
{
    int c=0;
    if (a[l]&(1<<kk)) c=1;
    //cout<<l<<" - "<<c<<endl;
    dp[0][l]=0;
    dp[1][l]=0;
    for (int j=0; j<v[l].size(); j++)
        if (v[l][j]!=pr)
    {
        dfs(v[l][j],l,kk);
        dp[0][l]+=dp[0][v[l][j]];
        dp[1][l]+=dp[1][v[l][j]];
        int to=v[l][j];
        if (c==0)
        {
            res+=dp[1][to];
            res+=dp[0][to]*(dp[1][l]-dp[1][to]);
            res+=dp[1][to]*(dp[0][l]-dp[0][to]);
        } else
        {
            res+=dp[0][to];
            res+=dp[0][to]*(dp[0][l]-dp[0][to]);
            res+=dp[1][to]*(dp[1][l]-dp[1][to]);
        }
    }
    if (c==1) {res++; swap(dp[0][l],dp[1][l]);}
    dp[c][l]++;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    for (int j=0; j<20; j++)
    {
        res=0;
        dfs(1,0,j);
        ans+=res*1ll*(1<<j);
        //cout<<res<<endl;
    }
    cout<<ans<<endl;
}
/**

  1(0)
  |
  2(1)
  |
  3(1)
 /  \
4(0) 5(0)


3 + 2 + 2 + 0 + 1 = 8
1 + 1 + 3 + 1 + 1 = 7
2 + 2 + 2 + 1 + 1 = 8

1 + 3 + 0 + 4 + 5 = 13
2 + 1 + 5 + 4 = 12
3 + 7 + 6 = 16
4 + 2 = 6
5 = 5

**/