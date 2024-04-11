#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
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
        lint N;
        cin >> N;
        vector<lint> e(N+1);
        REP(i, N) {
            lint etmp;
            cin >> etmp;
            e[etmp]++;
        }
        lint ans = 0;
        FOR(i, 1, N+1) {
            if(e[i] >= i) {
                ans++;
                e[i] -= i;
                i--;
            } else {
                if(i != N) {
                    e[i+1] += e[i];
                    e[i] = 0;
                }
            }
        }
        cout << ans << "\n";
    }
}