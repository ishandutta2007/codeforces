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
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
struct Node;
int n, k, ans=0;
vector<Node> V;
struct Node {
  vector<int> nbr;
  bool vst = false;
  bool leaf = false;
  int leaves = 0;
  int removed = 0;
  int dfs() {
    vst = true;
    if(nbr.size() == 1) {
        leaf = true;
        return 1;
    }
    for(int x : nbr) {
      if(!V[x].vst) {
        leaves += V[x].dfs();
      }
    }
    return 0;
  };
  void calc() {
    if(leaf) return;
    ans += leaves / k;
    removed += leaves / k * k;
    leaves = leaves - leaves / k * k;
    if(removed >= nbr.size()-1) {
        leaf = true;
        for(int x : nbr) {
            if(!V[x].leaf) {
                V[x].leaves++;
                if(V[x].leaves%k == 0) V[x].calc();
            }
        }
    }
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
        cin >> n >> k;
        REP(i, n) V.emplace_back();
        REP(i, n-1) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            V[x].nbr.push_back(y);
            V[y].nbr.push_back(x);
        }
        REP(i, n) {
            if(V[i].nbr.size() > 1) {
                V[i].dfs();
                break;
            }
        }
        ans = 0;
        REP(i, n) V[i].calc();
        cout << ans << "\n";
        V.clear();
    }

}