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
        lint a, K;
        cin >> a >> K;
        while(true) {
            K--;
            if(K == 0) break;
            lint min = 9;
            lint max = 0;
            lint tmp = a;
            while(tmp > 0) {
                lint x = tmp%10;
                if(x < min) min = x;
                if(x > max) max = x;
                tmp /= 10;
            }
            if(min == 0) {
                break;
            }
            a += min*max;
        }
        cout << a << "\n";
    }
}