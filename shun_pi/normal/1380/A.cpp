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
    int T;
    cin >> T;
    REP(t, T) {
        int n;
        cin >> n;
        vector<int> p(n);
        REP(i, n) cin >> p[i];
        int min = n+1;
        int idx = -1;
        bool flg = false;
        REP(i, n) {
            FOR(j, i+1, n) {
                if(p[i] > min && p[j] < p[i]) {
                    cout << "YES" << "\n";
                    cout << (idx+1) << " " << i+1 << " " << j+1 << "\n";
                    flg = true;
                }
                if(flg) break;
            }
            if(flg) break;
            if(p[i] < min) {
                min = p[i];
                idx = i;
            }
        }
        if(!flg) cout << "NO" << "\n";
    }
}