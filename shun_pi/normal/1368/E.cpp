#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<lint, lint>;
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
struct Node {
  int idx;
  multiset<int> nbr;
  bool valid = true;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    REP(t, T) {
        lint n, m;
        cin >> n >> m;
        REP(i, n) V.emplace_back();
        REP(i, m) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            V[u].nbr.insert(v);
        }
        set<P> pa;
        REP(i, n) {
            vector<P> deletep;
            for(P p : pa) {
                if(p.first > i) break; 
                deletep.push_back(p);
                if(V[p.second].valid) {
                    V[p.first].valid = false;
                }
            }
            REP(i, deletep.size()) pa.erase(deletep[i]);
            if(V[i].valid) {
                for(int x : V[i].nbr) {
                    for(int y : V[x].nbr) {
                        pa.insert(make_pair(y, x));
                    }
                }
            }
        }
        vector<int> ans;
        REP(i, n) if(!V[i].valid) ans.push_back(i+1);
        cout << ans.size() << "\n";
        REP(i, ans.size()) cout << ans[i] << (i!=ans.size()-1 ? " " : "");
        cout << "\n";
        V.clear();
    }
}