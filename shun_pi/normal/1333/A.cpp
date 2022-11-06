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
  cout << (expr ? "Yes" : "No") << endl;
}
int main()
{
    int T;
    cin >> T;
    REP(t, T) {
        int n, m;
        cin >> n >> m;
        vector<string> ans(n);
        REP(i, n) {
            REP(j, m) {
                if(n%2==0 || m%2==0) {
                    if(i==0 && j==0) {
                        ans[i] += "B";
                    } else if((i+j)%2==0) {
                        ans[i] += "W";
                    } else {
                        ans[i] += "B";
                    }
                } else {
                    if((i+j)%2==0) {
                        ans[i] += "B";
                    } else {
                        ans[i] += "W";
                    }
                }
            }
        }
        REP(i, n) cout << ans[i] << endl;
    }
}