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
        string s;
        cin >> s;
        int zeros = 0;
        int ones = 0;
        REP(i, s.size()){
            if(s[i] == '0') {
                zeros++;
            } else {
                ones++;
            }
        }
        int ans = min(zeros, ones);
        int l = 0;
        int r = ones;
        REP(i, s.size()) {
            if(s[i] == '1') {
                l++;
                r--;
            }
            int lz = (i+1)-l;
            int rz = (s.size()-1-i)-r;
            if(l+rz < ans) ans = l+rz;
            if(r+lz < ans) ans = r+lz;
        }
        cout << ans << "\n";
    }
}