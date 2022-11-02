#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define fr first
#define se second
#define pb push_back
#define inf 1e9
#define INF 1e18
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<class T>inline void chkmin(T&x,T y){if(y<x)x=y;}
template<class T>inline void chkmax(T&x,T y){if(x<y)x=y;}
#define N 30010

int dp[N][401], a[N];

int main() {
    int n, d, i, j, ans = 0;
    scanf("%d%d", &n, &d);
    for(i = 1; i <= n; i ++) scanf("%d", &j), a[j] ++;
    for(i = 0; i < N; i ++) for(j = 0; j < 401; j ++) dp[i][j] = -inf;
    if(d < 300) {
        dp[d][d] = a[d];
        for(i = d + 1; i < N; i ++) {
            for(j = 1; j < 400; j ++) if(i >= j) {
                chkmax(dp[i][j], dp[i - j][j - 1] + a[i]);
                chkmax(dp[i][j], dp[i - j][j] + a[i]);
                chkmax(dp[i][j], dp[i - j][j + 1] + a[i]);
            }
        }
    }
    if(d >= 300) {
        dp[d][100] = a[d];
        for(i = d + 1; i < N; i ++) {
            for(j = d - 100; j < d + 101; j ++) if(i >= j) {
                chkmax(dp[i][j + 100 - d], dp[i - j][j + 100 - d] + a[i]);
                chkmax(dp[i][j + 100 - d], dp[i - j][j + 101 - d] + a[i]);
                chkmax(dp[i][j + 100 - d], dp[i - j][j + 99 - d] + a[i]);
            }
        }
    }
    for(i = 0; i < N; i ++) for(j = 0; j < 400; j ++) chkmax(ans, dp[i][j]);
    printf("%d", ans);
}