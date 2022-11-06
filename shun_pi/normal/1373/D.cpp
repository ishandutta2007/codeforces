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
        lint n;
        cin >> n;
        vector<lint> a(n);
        REP(i, n) cin >> a[i];
        lint evensum = 0;
        REP(i, n) if(i%2 == 0) evensum += a[i];
        lint ans = 0;
        vector<lint> b(n/2);
        REP(i, n/2) b[i] = a[2*i+1] - a[2*i];
        FOR(i, 1, n/2) b[i] += b[i-1];
        lint mini = 0;
        REP(i, n/2) {
            if(b[i]-mini > ans) ans = b[i]-mini;
            if(b[i] < mini) mini = b[i];
        }
        vector<lint> c((n-1)/2);
        REP(i, (n-1)/2) c[i] = a[2*i+1] - a[2*i+2];
        FOR(i, 1, (n-1)/2) c[i] += c[i-1];
        mini = 0;
        REP(i, (n-1)/2) {
            if(c[i]-mini > ans) ans = c[i]-mini;
            if(c[i] < mini) mini = c[i];
        }
        cout << evensum + ans << "\n";
    }
}