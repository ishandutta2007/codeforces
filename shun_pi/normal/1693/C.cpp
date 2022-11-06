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
  int n, m;
  cin >> n >> m;
  vector<multiset<int>> nbr(n), rnbr(n);
  REP(i, m) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    nbr[u].insert(v);
    rnbr[v].insert(u);
  }
  vector<lint> d(n, 1e9);
  d[n-1] = 0;
  multiset<tuple<lint, int, int>> que;
  que.insert(make_tuple(0, 0, n-1));
  while(!que.empty()) {
    auto tup = *que.begin();
    lint dd = get<0>(tup);
    int m = get<1>(tup);
    int i = get<2>(tup);
    que.erase(tup);
    if(d[i] != dd) continue;
    if(m == 0) {
      for(int j : rnbr[i]) nbr[j].erase(nbr[j].find(i));
      que.insert(make_tuple(dd, 1, i));
    } else {
      for(int j : rnbr[i]) {
        lint nd = dd + 1 + nbr[j].size();
        if(nd < d[j]) {
          d[j] = nd;
          que.insert(make_tuple(nd, 0, j));
        }
      }
    }
  }
  cout << d[0] << endl;
}