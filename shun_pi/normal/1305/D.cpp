#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
struct Node;
vector<Node> V;
struct Node {
  int idx;
  vector<int> nbr;
  bool vst = false;
  int rem_nbr = 0;
  void dfs(int w) {
    vst = true;
    for(int x : nbr) {
        if(x == w) {
            V[w].rem_nbr++;
            continue;
        }
        if(!V[x].vst) {
            V[x].dfs(w);
        }
    }
  };
};
int main()
{
    int n;
    cin >> n;
    REP(i, n) {
        V.emplace_back();
        V[i].idx = i;
    }
    REP(i, n-1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        V[u].nbr.push_back(v);
        V[v].nbr.push_back(u);
    }
    vector<int> s;
    REP(i, n) {
        if(V[i].nbr.size() == 1) s.push_back(i);
        if(s.size() == 2) break;
    }
    int ans = -1;
    while(true) {
        cout << "? " << (s[0]+1) << " " << (s[1]+1) << endl;
        cout.flush();
        int w;
        cin >> w;
        w--;
        if(s[0] == w || s[1] == w) {
            ans = w;
            break;
        }
        V[s[0]].dfs(w);
        V[s[1]].dfs(w);
        vector<int> s_tmp;
        REP(i, n) {
            if((V[i].nbr.size() - V[i].rem_nbr) == 1 && !V[i].vst) {
                s_tmp.push_back(i);
            }
            if(s_tmp.size() == 2) break;
        }
        if(s_tmp.size() != 2) {
            ans = w;
            break;
        }
        s = s_tmp;
    }
    cout << "! " << (ans+1) << endl;
    cout.flush();
}