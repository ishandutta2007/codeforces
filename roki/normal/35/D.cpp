#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vvint vector<vint>
#define vint vector<int>
#define pdd pair<double,double>
typedef long long LL;
#pragma comment(linker, "/STACK:167177216")
int dp[10001];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k,ans = 0;
    dp[0] = 1;
    cin >> n >> k;
    for(int i = 0;i < n;++i)
    {
        int a;
        cin >> a;
        for(int j = k - 1;j >= 0;--j)
        {
            if(dp[j] > ans)
                ans = dp[j];
            if(dp[j] > 0 && j + (n - i) * a < 10001)
                dp[j + (n - i) * a] = max(dp[j + (n - i) * a],dp[j] + 1);
        }
    }
    for(int j = 0;j <= k;++j)
        ans = max(ans,dp[j]);
    cout << ans - 1 << endl;
    return 0;
}