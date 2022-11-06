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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lint n, k;
    cin >> n >> k;
    vector<lint> m(n);
    REP(i, n) cin >> m[i];
    vector<lint> c(k);
    REP(i, k) cin >> c[i];
    sort(m.begin(), m.end());
    vector<vector<lint>> ans(n, vector<lint>());
    lint lastc = -1;
    int idx = 0;
    IREP(i, n) {
        if(lastc != c[m[i]-1]) {
            lastc = c[m[i]-1];
            idx = 0;
        }
        while(ans[idx].size() >= c[m[i]-1]) {
            idx++;
        }
        ans[idx].push_back(m[i]);
    }
    lint out1 = 0;
    REP(i, n) {
        if(ans[i].size() > 0) out1++;
    }
    cout << out1 << "\n";
    REP(i, out1) {
        cout << ans[i].size() << " ";
        REP(j, ans[i].size()) cout << ans[i][j] << (j!=ans[i].size()-1 ? " " : "");
        cout << "\n";
    }
}