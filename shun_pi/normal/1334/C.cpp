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
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    REP(t, T) {
        int n;
        cin >> n;
        vector<lint> a(n);
        vector<lint> b(n);
        REP(i, n) {
            cin >> a[i] >> b[i];
        }
        lint ans = 0;
        REP(i, n) {
            ans += max(0LL, a[(i+1)%n] - b[i]);
        }
        lint mi = 1e12;
        REP(i, n) {
            lint red = min(a[(i+1)%n], b[i]);
            if(red < mi) mi = red;
        }
        ans += mi;
        cout << ans << "\n";
    }
}