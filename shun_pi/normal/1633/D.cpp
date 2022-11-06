#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<int, int>;
using PL = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr lint B1 = 1532834020;
constexpr lint M1 = 2147482409;
constexpr lint B2 = 1388622299;
constexpr lint M2 = 2147478017;
constexpr int INF = 2147483647;
void yes(bool expr) {cout << (expr ? "Yes" : "No") << "\n";}
template<class T>void chmax(T &a, const T &b) { if (a<b) a=b; }
template<class T>void chmin(T &a, const T &b) { if (b<a) a=b; }
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  vector<int> d(1001, 1e9);
  d[1] = 0;
  FOR(i, 1, 1001) FOR(j, 1, i+1) {
    if(i + i / j < 1001) chmin(d[i + i/j], d[i] + 1);
  }
  while(T--) {
    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    REP(i, n) cin >> b[i];
    vector<int> c(n);
    REP(i, n) cin >> c[i];
    int dsum = 0, csum = 0;
    REP(i, n) dsum += d[b[i]];
    REP(i, n) csum += c[i];
    if(dsum <= k) {
      cout << csum << "\n";
      continue;
    }
    vector<vector<int>> dp(n+1, vector<int>(k+1));
    REP(i, n) REP(j, k+1) {
      chmax(dp[i+1][j], dp[i][j]);
      if(j+d[b[i]] <= k) chmax(dp[i+1][j+d[b[i]]], dp[i][j] + c[i]);
    }
    int ans = 0;
    REP(i, k+1) chmax(ans, dp[n][i]);
    cout << ans << "\n";
  }
}