#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string.h>
using namespace std;
typedef long long ll;
#define fastio ios::sync_with_stdio(false)
#define INF 1e18
#define max(a, b) a<b?b:a
#define min(a, b) a<b?a:b
#define abs(x) x<0?-x:x
const int MOD = 1e9 + 7;
const int MAXN = 300 + 10;
int n, dp[MAXN];
char s[MAXN];
int main()
{
    cin >> n;
    scanf("%s", s+1);
    int i , x = 0, y = 0;
    bool in = 0;
    for(i = 1; i <= n; i++)
    {
        if(s[i] == '_'){
           dp[i] = 0;
           if(in && (dp[i-1] > 0)) y++;
        }else if(s[i] == '(')
        {
            in = 1;
            dp[i] = 0;
        }else if(s[i] == ')'){
            in = 0;
            dp[i] = 0;
            if(dp[i - 1] > 0) y++;
        }else{
            dp[i] = dp[i-1] + 1;
            if(!in) x = max(x, dp[i]);
        }
    }
    cout << x << " " << y << endl;
}