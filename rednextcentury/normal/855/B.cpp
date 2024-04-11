#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define oo 1000000000000000000000
using namespace std;

const int N = 100005;
ll dp[N][5];
bool vis[N][5];
ll a[N];
ll c[5];
int n;

ll solve(int i, int j)
{
    if(j == 3)
        return 0;

    if(i == n)
        return -oo;

    if(vis[i][j])
            return dp[i][j];
    vis[i][j]=1;
    ll res = max(solve(i+1, j), c[j]*a[i]+solve(i, j+1));
    return dp[i][j] = res;
}

int main()
{
    cin>>n>>c[0]>>c[1]>>c[2];
    for(int i = 0; i < n; i++)
      scanf("%I64d",&a[i]);

    cout<<solve(0,0);

  return 0;
}