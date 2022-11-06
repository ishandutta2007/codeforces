#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
struct Node;
vector<Node> V;
struct Node {
  int idx;
  vector<int> nbr;
  bool grp0 = true;
  bool vst = false;
  int dfs() {
    vst = true;
    int nbridx = 0;
    sort(nbr.begin(), nbr.end());
    REP(i, V.size()) {
        if(nbridx < nbr.size() && i == nbr[nbridx]) {
            nbridx++;
            continue;
        }
        if(V[i].grp0) {
            grp0 = true;
            return 0;
        }
        if(!V[i].vst) {
            int ret = V[i].dfs();
            if(ret == 0) {
                grp0 = true;
                return 0;
            }
        }
    }
    return 1;
  };
};
int main()
{
    lint n, m;
    cin >> n >> m;

    V = vector<Node>(n);
    REP(i, n) {
        V[i] = Node();
        V[i].idx = i;
    }
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        V[a-1].nbr.push_back(b-1);
        V[b-1].nbr.push_back(a-1);
    }
    sort(V.begin(), V.end(),
       [](auto const &a, auto const &b) { return a.nbr.size() < b.nbr.size(); });
    int tmpidx = V[0].idx;
    sort(V.begin(), V.end(),
       [](auto const &a, auto const &b) { return a.idx < b.idx; });
    for(int x : V[tmpidx].nbr) {
        V[x].grp0 = false;
    }
    
    int ans = 0;
    REP(i, n) {
        if(!V[i].grp0 && !V[i].vst) {
            //cout << i << endl;
            ans += V[i].dfs();
        }
    }
    cout << ans << endl;
}