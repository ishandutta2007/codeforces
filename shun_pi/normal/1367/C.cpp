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
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        string tmp = "";
        REP(i, k) tmp += '0';
        s = "1" + tmp + s + tmp + "1";
        int ans = 0;
        int now = 0;
        REP(i, s.size()) {
            if(s[i] == '0') {
                now++;
                if(now == 2*k+1) {
                    now -= k+1;
                    ans++;
                }
            } else {
                now = 0;
            }
        }
        cout << ans << "\n";
    }
}