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
constexpr int INF = 2147483647;
void yes(bool expr) {cout << (expr ? "Yes" : "No") << "\n";}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  lint n, m;
  cin >> n >> m;
  vector<string> c(n);
  REP(i, n) cin >> c[i];
  vector<vector<lint>> b(n, vector<lint>(m));
  deque<PL> que;
  vector<int> dx = {1, -1, 0, 0};
  vector<int> dy = {0, 0, 1, -1};
  REP(i, n) REP(j, m) {
    if(i == 0 || i == n-1 || j == 0 || j == m-1) {
      b[i][j] = 1;
      que.push_back(PL(i, j));
      continue;
    }
    bool flg = false;
    REP(k, 4) {
      if(c[i][j] != c[i+dx[k]][j+dy[k]]) {
        flg = true;
        break;
      }
    }
    if(flg) {
      b[i][j] = 1;
      que.push_back(PL(i, j));
      continue;
    }
  }
  while(!que.empty()) {
    PL pa = que.front();
    que.pop_front();
    REP(k, 4) {
      if(pa.first+dx[k] < 0 || pa.first+dx[k] >= n || pa.second+dy[k] < 0 || pa.second+dy[k] >= m) continue;
      if(b[pa.first+dx[k]][pa.second+dy[k]] == 0) {
        b[pa.first+dx[k]][pa.second+dy[k]] = b[pa.first][pa.second] + 1;
        que.push_back(PL(pa.first+dx[k], pa.second+dy[k]));
      }
    }
  }
  lint ans = 0;
  REP(i, n) REP(j, m) ans += b[i][j];
  cout << ans << endl;
}