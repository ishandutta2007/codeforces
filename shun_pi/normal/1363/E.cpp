#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
struct Node;
vector<Node> V;
lint ans = 0;
struct Node {
  int idx;
  lint a;
  int b;
  int c;
  bool valid = 0;
  vector<int> nbr;
  bool vst = false;
  void dfs(lint mini) {
    vst = true;
    if(mini < a) {
        a = mini;
    } else {
        mini = a;
    }
    for(int x : nbr) {
      if(!V[x].vst) {
        V[x].dfs(mini);
      }
    }
  };
  pair<int, int> dfs2() {
    vst = true;
    int zeroone = 0;
    int onezero = 0;
    for(int x : nbr) {
      if(!V[x].vst) {
        auto ret = V[x].dfs2();
        zeroone += ret.first;
        onezero += ret.second;
      }
    }
    if(b == 0 && c == 1) zeroone++;
    if(b == 1 && c == 0) onezero++;
    while (zeroone >= 1 && onezero >= 1) {
        ans += a*2;
        zeroone--;
        onezero--;
    }
    return make_pair(zeroone, onezero);
  };
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lint n;
    cin >> n;
    int aones = 0;
    int bones = 0;
    REP(i, n) {
        V.emplace_back();
        V[i].idx = i;
        cin >> V[i].a >> V[i].b >> V[i].c;
        if(V[i].b == 1) aones++;
        if(V[i].c == 1) bones++;
    }
    REP(i, n-1) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        V[u].nbr.push_back(v);
        V[v].nbr.push_back(u);
    }
    if(aones != bones) {
        cout << -1 << endl;
        return 0;
    }
    V[0].dfs(1e9);
    REP(i, n) V[i].vst = false;
    V[0].dfs2();
    cout << ans << endl;

}