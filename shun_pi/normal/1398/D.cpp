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
vector<lint> r;
vector<lint> g;
vector<lint> b;
int R, G, B;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> R >> G >> B;
  r = vector<lint>(R);
  REP(i, R) cin >> r[i];
  g = vector<lint>(G);
  REP(i, G) cin >> g[i];
  b = vector<lint>(B);
  REP(i, B) cin >> b[i];
  sort(ALL(r), greater<int>());
  sort(ALL(g), greater<int>());
  sort(ALL(b), greater<int>());
  vector<vector<vector<lint>>> dp(R+2, vector<vector<lint>>(G+2, vector<lint>(B+2, -1)));
  lint ans = 0;
  dp[0][0][0] = 0;
  REP(i, R+1) REP(j, G+1) REP(k, B+1) {
    if(dp[i][j][k] == -1) continue;
    ans = max(ans, dp[i][j][k]);
    dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k] + r[i]*g[j]);
    dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k] + r[i]*b[k]);
    dp[i][j+1][k+1] = max(dp[i][j+1][k+1], dp[i][j][k] + g[j]*b[k]);
  }
  cout << ans << endl;
}