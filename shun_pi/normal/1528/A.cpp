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
  vector<int> nbr;
  lint l, r, lmax = 0, rmax = 0;
  bool vst = false;
  void dfs() {
    vst = true;
    lmax = 0;
    rmax = 0;
    for(int x : nbr) if(!V[x].vst) {
      V[x].dfs();
      lmax += max(abs(l - V[x].l) + V[x].lmax, abs(l - V[x].r) + V[x].rmax);
      rmax += max(abs(r - V[x].l) + V[x].lmax, abs(r - V[x].r) + V[x].rmax);
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
    int n;
    cin >> n;
    V = vector<Node>(n);
    REP(i, n) cin >> V[i].l >> V[i].r;
    REP(i, n-1) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      V[u].nbr.push_back(v);
      V[v].nbr.push_back(u);
    }
    V[0].dfs();
    cout << max(V[0].lmax, V[0].rmax) << "\n";
  }
}