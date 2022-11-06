#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
struct Node;
vector<Node> V(26);
struct Node {
  set<int> nbr = {};
  bool vst = true;
  void dfs() {
    vst = true;
    for(int x : nbr) {
      if(!V[x].vst) {
        V[x].dfs();
      }
    }
  };
};

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    REP(i, n) cin >> s[i];
    REP(i, 26) Node V[i];

    REP(i, n) {
        REP(j, s[i].size()-1) {
            V[s[i][j] - 'a'].nbr.insert(s[i][j+1] - 'a');
            V[s[i][j+1] - 'a'].nbr.insert(s[i][j] - 'a');
        }
        REP(j, s[i].size()) {
            V[s[i][j] - 'a'].vst = false;
        }
    }

    int ans = 0;
    REP(i, 26) {
        if(!V[i].vst) {
            ans++;
            V[i].dfs();
        }
    }
    cout << ans << endl;
}