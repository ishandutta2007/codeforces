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
    lint n, m, x, k, y;
    cin >> n >> m >> x >> k >> y;
    vector<lint> a(n+1);
    REP(i, n) cin >> a[i];
    vector<lint> b(m);
    REP(i, m) cin >> b[i];
    lint bidx = 0;
    lint tmp = 0;
    lint inmax = 0;
    lint incnt = 0;
    lint ans = 0;
    REP(i, n+1) {
        if(i == n || (bidx < m && a[i] == b[bidx])) {
            lint p = incnt / k;
            lint q = incnt % k;
            if(inmax > max(tmp, a[i])) {
                if(p == 0) {
                    cout << -1 << endl;
                    return 0;
                }
                ans += x;
                p--;
            }
            ans += p*min(x, y*k) + q*y;
            inmax = 0;
            incnt = 0;
            tmp = a[i];
            if(i != n) bidx++;
        } else {
            inmax = max(inmax, a[i]);
            incnt++;
        }
    }
    if(bidx != m) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}