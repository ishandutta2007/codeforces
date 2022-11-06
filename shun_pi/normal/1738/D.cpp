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
vector<int> ans;
int n, k;
struct Node {
  int idx;
  bool vst = false;
  vector<int> nbr;
  void dfs() {
    vst = true;
    if(idx != 0 && idx != n+1) ans.push_back(idx);
    for(int x : nbr) if(!V[x].vst && V[x].nbr.size() == 0) {
      V[x].dfs();
      if(x < idx) chmax(k, x);
    }
    for(int x : nbr) if(!V[x].vst) {
      V[x].dfs();
      if(x < idx) chmax(k, x);
    }
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
    cin >> n;
    vector<int> b(n);
    REP(i, n) cin >> b[i];
    V = vector<Node>(n+2);
    REP(i, n+2) V[i].idx = i;
    REP(i, n) V[b[i]].nbr.push_back(i+1);
    ans.clear();
    k = 0;
    V[0].dfs();
    V[n+1].dfs();
    cout << k << "\n";
    REP(i, n) cout << ans[i] << (i!=n-1 ? " " : "");
    cout << "\n";
  }
}