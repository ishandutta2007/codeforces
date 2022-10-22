#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;
#define N 100005
#define M 500005
int n , dp[N] , a[N];
int digit[N];

int dfs(int pos , bool doing)
{
    if(pos == -1)
        return 0;
    if(!doing && ~dp[pos])
        return dp[pos];
    int ans = 0;
    int end = doing ? digit[pos] : 1;
    for(int i = 0 ; i <= end ; i ++)
        ans = max(ans , dfs(pos - 1 , doing && i == end) + (i == 1) * a[pos]);
    if(!doing)
      dp[pos] = ans;
    return ans;
}

void work()
{
    int i;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&a[i]);
    for (i = 0 ; i < n ; ++ i)
        scanf("%1d",&digit[i]);
    memset(dp , -1 , sizeof(dp));
    cout << dfs(n - 1 , 1) << endl;
}

int main()
{
  //freopen("~output.txt","w",stdout);
  //while (scanf("%d%d",&n,&m) , n || m)
  //int _; cin >> _;while (_--)
    work();
  return 0;
}