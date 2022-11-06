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
lint loopidx = 0;
struct Node {
  int d;
  int idx;
  vector<int> nbr;
  bool vst = false;
  bool loop = false;
  bool dfs(int _d) {
    if(vst && _d-d > 2) {
      loopidx = idx;
      return true;
    } else if(vst) return false;
    vst = true;
    d = _d;
    bool ret = false;
    for(int x : nbr) if(V[x].dfs(d+1)) ret = true;
    loop = ret;
    if(ret && idx == loopidx) ret = false;
    return ret;
  };
  lint dfs2() {
    vst = true;
    lint ret = 1;
    for(int x : nbr) if(!V[x].vst && !V[x].loop) ret += V[x].dfs2();
    return ret;
  }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while(T--) {
    lint n;
    cin >> n;
    V = vector<Node>(n);
    REP(i, n) V[i].idx = i;
    REP(i, n) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      V[u].nbr.push_back(v);
      V[v].nbr.push_back(u);
    }
    V[0].dfs(0);
    lint ans = n*(n-1);
    REP(i, n) V[i].vst = false;
    REP(i, n) {
      if(V[i].loop) {
        vector<lint> rets;
        for(int x : V[i].nbr) {
          if(!V[x].loop) rets.push_back(V[x].dfs2());
        }
        lint sum = 1;
        REP(i, rets.size()) sum += rets[i];
        ans -= sum*(sum-1) / 2;
      }
    }
    cout << ans << "\n";
    
  }
}