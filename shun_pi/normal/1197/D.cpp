#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
int main()
{
    int n, m;
    lint k;
    cin >> n >> m >> k;
    vector<lint> a(n);
    REP(i, n) cin >> a[i];
    vector<vector<lint>> dp(n+1,vector<lint>(m));
    lint ansmax = 0;
    REP(i, n+1) {
        REP(j, m) {
            if(i == 0) {
                dp[i][j] = 0;
            } else {
                if(j == 0) {
                    dp[i][j] = max(a[i-1], dp[i-1][m-1] + a[i-1]) - k;
                } else {
                    if(i > j) {
                        dp[i][j] = dp[i-1][j-1] + a[i-1];
                    } else {
                        dp[i][j] = 0;
                    }
                }
            }
            if(dp[i][j] > ansmax) ansmax = dp[i][j];
        }
    }
    cout << ansmax << endl;
}