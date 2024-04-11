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
  bool teach = false;
  vector<int> nbr;
  bool vst = false;
  void dfs() {
    vst = true;
    for(int x : nbr) if(!V[x].vst) V[x].dfs();
  };
  void dfs2() {
    vst = true;
    bool tmp = true;
    for(int x : nbr) if(V[x].teach) tmp = false;
    teach = tmp;
    for(int x : nbr) if(!V[x].vst) V[x].dfs2();
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
    lint n, m;
    cin >> n >> m;
    V = vector<Node>(n);
    REP(i, m) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      V[u].nbr.push_back(v);
      V[v].nbr.push_back(u);
    }
    V[0].dfs();
    bool ok = true;
    REP(i, n) if(!V[i].vst) ok = false;
    if(!ok) {
      cout << "NO" << "\n";
      continue;
    }
    cout << "YES" << "\n";
    REP(i, n) V[i].vst = false;
    V[0].dfs2();
    vector<int> ans;
    REP(i, n) if(V[i].teach) ans.push_back(i+1);
    cout << ans.size() << "\n";
    REP(i, ans.size()) cout << ans[i] << (i!=ans.size()-1 ? " " : "");
    cout << "\n";
  }
}