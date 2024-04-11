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
        lint l, r, m;
        cin >> l >> r >> m;
        lint b = 0;
        lint c = 0;
        FOR(a, l, r+1) {
            lint p = m / a;
            lint q = m % a;
            if(p >= 1 && q <= r-l) {
                cout << a << " " << l+q << " " << l << "\n";
                break;
            } else if(p >= 0 && q >= a - (r-l)) {
                cout << a << " " << l << " " << l+(a-q) << "\n";
                break;
            }
        }
    }
}