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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    REP(t, T) {
        int n, k;
        cin >> n >> k;
        int a = k / n;
        int b = k % n;
        vector<vector<int>> ans(n, vector<int>(n));
        REP(i, n) {
            REP(j, a+1) {
                if(j == a && i >= b) break;
                ans[i][(i+j)%n] = 1;
            }
        }
        if(b == 0) {
            cout << 0 << "\n";
        } else {
            cout << 2 << "\n";
        }
        REP(i, n) {
            REP(j, n) cout << ans[i][j];
            cout << "\n";
        }
    }
}