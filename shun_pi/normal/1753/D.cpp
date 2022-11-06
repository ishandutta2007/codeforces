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
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};
vector<char> dc = {'U', 'L', 'D', 'R'};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  lint n, m, p, q;
  cin >> n >> m >> p >> q;
  vector<string> s(n);
  REP(i, n) cin >> s[i];
  vector<vector<lint>> dp(n, vector<lint>(m, 1e18));
  set<tuple<lint, int, int>> st;
  REP(i, n) REP(j, m) if(s[i][j] == '.') {
    dp[i][j] = 0;
    st.insert(make_tuple(0, i, j));
  }
  while(!st.empty()) {
    int x = get<1>(*st.begin());
    int y = get<2>(*st.begin());
    st.erase(st.begin());
    REP(d, 4) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if(s[nx][ny] == dc[(d+2)%4]) {
        int nnx = nx + dx[d];
        int nny = ny + dy[d];
        if(dp[x][y] + q < dp[nnx][nny]) {
          dp[nnx][nny] = dp[x][y] + q;
          st.insert(make_tuple(dp[nnx][nny], nnx, nny));
        }
      } else if(s[nx][ny] == dc[(d+1)%4]) {
        int nnx = nx + dx[(d+3)%4];
        int nny = ny + dy[(d+3)%4];
        if(dp[x][y] + p < dp[nnx][nny]) {
          dp[nnx][nny] = dp[x][y] + p;
          st.insert(make_tuple(dp[nnx][nny], nnx, nny));
        }
      } else  if(s[nx][ny] == dc[(d+3)%4]) {
        int nnx = nx + dx[(d+1)%4];
        int nny = ny + dy[(d+1)%4];
        if(dp[x][y] + p < dp[nnx][nny]) {
          dp[nnx][nny] = dp[x][y] + p;
          st.insert(make_tuple(dp[nnx][nny], nnx, nny));
        }
      }
    } 
  }
  lint ans = 1e18;
  REP(i, n) REP(j, m) {
    if(i < n-1) chmin(ans, dp[i][j] + dp[i+1][j]);
    if(j < m-1) chmin(ans, dp[i][j] + dp[i][j+1]);
  }
  if(ans == 1e18) cout << -1 << endl;
  else cout << ans << endl;
}