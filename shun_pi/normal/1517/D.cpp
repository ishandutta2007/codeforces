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
vector<int> dx={-1, 1, 0, 0};
vector<int> dy={0, 0, -1, 1};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> h(n, vector<int>(m-1));
  REP(i, n) REP(j, m-1) cin >> h[i][j];
  vector<vector<int>> v(n-1, vector<int>(m));
  REP(i, n-1) REP(j, m) cin >> v[i][j];
  if(k%2 != 0) {
    REP(i, n) {
      REP(j, m) cout << -1 << (j!=m-1 ? " " : "");
      cout << "\n";
    }
    return 0;
  }
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, 1e9)));
  REP(i, n) REP(j, m) dp[i][j][0] = 0;
  REP(i, n) REP(j, m) {
    if(i-1 >= 0) chmin(dp[i][j][1], v[i-1][j]);
    if(i < n-1) chmin(dp[i][j][1], v[i][j]);
    if(j-1 >= 0) chmin(dp[i][j][1], h[i][j-1]);
    if(j < m-1) chmin(dp[i][j][1], h[i][j]);
  }
  FOR(l, 2, k+1) REP(i, n) REP(j, m) {
    if(i-1 >= 0) chmin(dp[i][j][l], v[i-1][j]+dp[i-1][j][l-1]);
    if(i < n-1) chmin(dp[i][j][l], v[i][j]+dp[i+1][j][l-1]);
    if(j-1 >= 0) chmin(dp[i][j][l], h[i][j-1]+dp[i][j-1][l-1]);
    if(j < m-1) chmin(dp[i][j][l], h[i][j]+dp[i][j+1][l-1]);
  }
  REP(i, n) REP(j, m) REP(p, k+1) REP(q, p+1) chmin(dp[i][j][p], dp[i][j][q] + dp[i][j][p-q]);
  REP(i, n) {
    REP(j, m) cout << dp[i][j][k/2]*2 << (j!=m-1 ? " " : "");
    cout << "\n";
  }
}