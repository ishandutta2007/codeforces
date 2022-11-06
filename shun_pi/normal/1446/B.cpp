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
  int n, m;
  cin >> n >> m;
  string A, B;
  cin >> A >> B;
  vector<vector<int>> dp(n+1, vector<int>(m+1));
  vector<vector<int>> mx(n+1, vector<int>(m+1));
  REP(i, n) REP(j, m) {
    if(A[i] == B[j]) chmax(dp[i+1][j+1], dp[i][j] + 2);
    chmax(dp[i+1][j+1], dp[i+1][j] - 1);
    chmax(dp[i+1][j+1], dp[i][j+1] - 1);
  }
  IREP(i, n+1) IREP(j, m+1) {
    mx[i][j] = dp[i][j];
    if(i != n) chmax(mx[i][j], mx[i+1][j]);
    if(j != m) chmax(mx[i][j], mx[i][j+1]);
  }
  int ans = 0;
  REP(i, n+1) REP(j, m+1) chmax(ans, mx[i][j] - dp[i][j]);
  cout << ans << endl;
}