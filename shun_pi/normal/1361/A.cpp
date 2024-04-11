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
  int topic = -1;
  vector<int> nbr;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lint n, m;
    cin >> n >> m;
    REP(i, n) V.emplace_back();
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        V[a].nbr.push_back(b);
        V[b].nbr.push_back(a);
    }
    vector<P> t(n);
    REP(i, n) {
        int tt;
        cin >> tt;
        t[i] = make_pair(tt, i);
    }
    sort(ALL(t), [](auto const &a, auto const &b) { return a.first < b.first; });
    vector<int> ans;
    REP(i, n) {
        V[t[i].second].topic = t[i].first;
        vector<bool> topiccnt(t[i].first);
        //cout << t[i].second+1 << " " << t[i].first << endl;
        for(int x : V[t[i].second].nbr) {
            if(V[x].topic == t[i].first) {
                cout << -1 << endl;
                return 0;
            } else if(V[x].topic != -1 && V[x].topic < t[i].first) {
                topiccnt[V[x].topic] = true;
            }
        }
        FOR(j, 1, t[i].first) {
            if(!topiccnt[j]) {
                cout << -1 << endl;
                return 0;
            }
        }
        ans.push_back(t[i].second+1);
    }
    REP(i, n) cout << ans[i] << (i!=n-1 ? " " : "");
    cout << "\n";
}