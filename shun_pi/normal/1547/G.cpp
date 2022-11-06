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
struct Node;
vector<Node> V;
struct Node {
  int idx;
  vector<int> nbr;
  int ans = 0;
  void dfs(bitset<400000> &bs, int mode) {
    if(ans == 1 && mode == 1) mode = 2;
    if(bs[idx]) mode = 3;
    if(ans >= mode) return;
    ans = mode;
    bs.set(idx);
    for(int x : nbr) V[x].dfs(bs, mode);
    bs.reset(idx);
  };
};
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
    V = vector<Node>(n);
    REP(i, n) V[i].idx = i;
    REP(i, m) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      V[a].nbr.push_back(b);
    }
    bitset<400000> bs;
    V[0].dfs(bs, 1);
    REP(i, n) if(V[i].ans == 3) V[i].ans = -1;
    REP(i, n) cout << V[i].ans << (i!=n-1 ? " " : "");
    cout << "\n";
  }
}