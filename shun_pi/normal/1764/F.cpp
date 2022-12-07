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
  int n;
  cin >> n;
  vector<vector<lint>> f(n, vector<lint>(n));
  REP(i, n) REP(j, i+1) cin >> f[i][j];
  REP(i, n) FOR(j, i+1, n) f[i][j] = f[j][i];
  vector<tuple<int, int, lint>> ans;
  vector<bool> done(n);
  vector<int> par(n);
  vector<lint> sum(n);
  REP(i, n) sum[i] = f[i][i];
  REP(k, n-1) {
    lint ma = -1;
    int x = 0;
    REP(i, n) if(!done[i] && sum[i] > ma) {
      ma = sum[i];
      x = i;
    }
    ma = f[x][x];
    lint ma2 = -1;
    int y = 0;
    REP(i, n) if(!done[i] && i != x && f[x][i] > ma2) {
      ma2 = f[x][i];
      y = i;
    }
    assert((ma - ma2) % (n-1-par[x]) == 0);
    lint d = (ma - ma2) / (n-1-par[x]);
    ans.push_back(make_tuple(x, y, d));
    done[x] = true;
    par[y] += par[x] + 1;
    /*
    lint last = d;
    IREP(i, n) {
      int y = fx[i].second;
      if(!done[y]) {
        sum[y] -= last;
        last = sum[y];
      }
    } 
    */
  }
  REP(i, n-1) cout << get<0>(ans[i])+1 << " " << get<1>(ans[i])+1 << " " << get<2>(ans[i]) << "\n";
}