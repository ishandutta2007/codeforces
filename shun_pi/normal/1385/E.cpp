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
vector<Node> V;
vector<int> L;
struct Node {
  int idx;
  int top;
  int vst = 0;
  vector<int> nbr;
  bool visit() {
    bool ret = true;
    if(vst == 1) return false;
    else if(vst == 0) {
        vst = 1;
        for(int x : nbr) if(!V[x].visit()) ret = false;
        vst = 2;
        L.push_back(idx);
    }
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
        int n, m;
        cin >> n >> m;
        REP(i, n) V.emplace_back();
        REP(i, n) V[i].idx = i;
        vector<int> t(m);
        vector<int> x(m);
        vector<int> y(m);
        REP(i, m) {
            cin >> t[i] >> x[i] >> y[i];
            x[i]--; y[i]--;
            if(t[i] == 1) V[x[i]].nbr.push_back(y[i]);
        }
        bool flg = true;
        REP(i, n) {
            if(V[i].vst == 0) {
                if(!V[i].visit()) {
                    flg = false;
                    break;
                }
            }
        }
        if(!flg) {
            cout << "NO" << "\n";
            V.clear();
            L.clear();
            continue;
        }
        REP(i, n) V[L[i]].top = n-i;
        cout << "YES" << "\n";
        REP(i, m) {
            if(t[i] == 1 || V[x[i]].top < V[y[i]].top) {
                cout << (x[i]+1) << " " << (y[i]+1) << "\n";
            } else {
                cout << (y[i]+1) << " " << (x[i]+1) << "\n";
            }
        }
        V.clear();
        L.clear();

    }
}