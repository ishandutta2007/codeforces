#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
int main()
{
    int T;
    cin >> T;
    REP(t, T) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        REP(i, n) cin >> a[i];
        vector<int> b(m);
        REP(i, m) cin >> b[i];
        vector<int> order(n+1);
        REP(i, n) {
            order[a[i]] = i;
        }
        lint ans = 0;
        lint maxorder = 0; 
        REP(i, m) {
            if(order[b[i]] <= maxorder) {
                ans++;
            } else {
                maxorder = order[b[i]];
                ans += 2*(maxorder - i) + 1;
            }
        }
        cout << ans << endl;
    }
}