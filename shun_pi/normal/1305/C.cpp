#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<lint> a(n);
    REP(i, n) {
        cin >> a[i];
    }
    if(n > m) {
        cout << 0 << endl;
        return 0;
    }
    lint ans = 1;
    REP(i, n) {
        FOR(j, i+1, n) {
            ans = (ans * abs(a[i] - a[j])) % m;
        }
    }
    cout << ans << endl;
}