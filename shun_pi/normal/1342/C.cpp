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
        lint a, b, q;
        cin >> a >> b >> q;
        if(b < a) swap(a, b);
        vector<bool> div(a);
        REP(i, a) {
            if((b*i)%a == 0) div[i] = true;
        }
        lint p = a*b;
        lint x = 0;
        REP(i, a) {
            if(!div[i]) x += b;
        }
        REP(i, q) {
            lint l, r;
            cin >> l >> r;
            l--;
            lint ans = r / p * x;
            r %= p;
            lint idx = 0;
            r++;
            while(r > 0) {
                if(!div[idx]) ans += min(b, r);
                r -= b;
                idx++;
            }
            ans -= l / p * x;
            l %= p;
            idx = 0;
            l++;
            while(l > 0) {
                if(!div[idx]) ans -= min(b, l);
                l -= b;
                idx++;
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}