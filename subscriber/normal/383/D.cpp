#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 211111
using namespace std;
typedef pair<int,int> pt;

int n, a[1111];
int dp[1011][20111];

int main(){
    cin >> n;
    for (int i = 0 ; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) dp[i][10000] = 1;
    for (int i = 0; i < n; i++) for (int j = 0; j < 20000; j++) if (dp[i][j] > 0) {
        dp[i + 1][j + a[i]] += dp[i][j];
        if (dp[i + 1][j + a[i]] >= M) dp[i + 1][j + a[i]] -= M;
        dp[i + 1][j - a[i]] += dp[i][j];
        if (dp[i + 1][j - a[i]] >= M) dp[i + 1][j - a[i]] -= M;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) ans = (ans + dp[i][10000]) % M;
    ans = (ans - n + M) % M;
    cout << ans << endl;
    return 0;
}