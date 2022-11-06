#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
struct Node;
vector<Node> V;
lint maxi;
struct Node {
  int idx;
  vector<int> nbr;
  bool vst = false;
  int depth = 0;
  void dfs(int d) {
    depth = d;
    vst = true;
    lint len1 = 0;
    for(int x : nbr) {
        if(V[x].nbr.size() == 1) {
            len1++;
        }
      if(!V[x].vst) {
        V[x].dfs(d+1);
      }
    }
    maxi -= max(0LL, len1-1);
  };
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lint n;
    cin >> n;
    REP(i, n) V.emplace_back();
    REP(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].nbr.push_back(b);
        V[b].nbr.push_back(a);
    }
    maxi = n-1;
    REP(i, n) {
        if(V[i].nbr.size() == 1) {
            V[i].dfs(0);
            break;
        }
    }
    int min = 1;
    REP(i, n) {
        if(V[i].nbr.size() == 1 && V[i].depth%2 != 0) {
            min = 3;
            break;
        }
    }
    cout << min << " " << maxi << endl;
    

}