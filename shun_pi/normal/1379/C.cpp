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
void yes(bool expr) {cout << (expr ? "Yes" : "No") << "\n";}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        lint n, m;
        cin >> n >> m;
        vector<lint> a(m);
        vector<lint> b(m);
        REP(i, m) cin >> a[i] >> b[i];
        vector<lint> asort(a);
        sort(ALL(asort), greater<lint>());
        vector<lint> Sasort(m+1);
        REP(i, m) Sasort[i+1] = Sasort[i] + asort[i];
        lint ans = 0;
        REP(i, m) {
            lint l = -1;
            lint r = m;
            while(r-l > 1) {
                lint x = (l+r) / 2;
                if(asort[x] >= b[i]) l = x;
                else r = x;
            }
            lint sum = 0;
            if(a[i] < b[i]) {
                lint cnt = min(r, n-1);
                sum = a[i] + Sasort[cnt] + (n-1-cnt)*b[i];
            } else {
                lint cnt = min(r, n);
                sum = Sasort[cnt] + (n-cnt)*b[i];
            }
            ans = max(ans, sum);
        }
        cout << ans << "\n";
    }
}