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
  while(T--) {
    int n, m;
    cin >> n >> m;
    vector<lint> u(m), v(m), w(m);
    vector<vector<PL>> nbr(n);
    REP(i, m) {
      cin >> u[i] >> v[i] >> w[i];
      u[i]--; v[i]--;
      nbr[u[i]].push_back(PL(v[i], w[i]));
      nbr[v[i]].push_back(PL(u[i], w[i]));
    }
    vector<vector<lint>> d(n, vector<lint>(n, 1e18));
    REP(i, n) {
      d[i][i] = 0;
      deque<int> que;
      que.push_back(i);
      while(!que.empty()) {
        int x = que.front();
        que.pop_front();
        for(P p : nbr[x]) {
          int y = p.first;
          if(d[i][x] + 1 < d[i][y]) {
            d[i][y] = d[i][x] + 1;
            que.push_back(y);
          }
        }
      }
    }
    lint ans = 1e18;
    REP(i, m) {
      chmin(ans, w[i] * (d[0][u[i]] + d[v[i]][n-1] + 1));
      chmin(ans, w[i] * (d[0][v[i]] + d[u[i]][n-1] + 1));
      REP(j, n) {
        chmin(ans, w[i] * (d[0][j] + d[j][n-1] + d[j][u[i]] + 2));
        chmin(ans, w[i] * (d[0][j] + d[j][n-1] + d[j][v[i]] + 2));
      }
    }
    cout << ans << "\n";
  }
}