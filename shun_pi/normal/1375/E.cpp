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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];

    vector<vector<int>> pa(n);
    REP(i, n) {
        FOR(j, i+1, n) {
            if(a[i] > a[j]) pa[i].push_back(j);
        }
    }
    vector<P> ans;
    REP(i, n) {
        vector<P> tmp;
        REP(j, pa[i].size()) tmp.push_back(make_pair(pa[i][j], a[pa[i][j]]));
        sort(ALL(tmp), [](auto const &a, auto const &b) { return a.second != b.second ? a.second > b.second : a.first > b.first; });
        REP(j, tmp.size()) ans.push_back(make_pair(i, tmp[j].first));
    }
    cout << ans.size() << "\n";
    REP(i, ans.size()) cout << ans[i].first+1 << " " << ans[i].second+1 << "\n";
    
}