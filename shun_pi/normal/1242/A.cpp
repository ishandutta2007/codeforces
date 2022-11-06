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
    lint n;
    cin >> n;
    bool flg = false;
    lint ans = n;
    for(lint i=2; i*i<=n; i++) {
        if(n%i == 0) {
            n = n / i;
            while(n > 1) {
                if(n%i != 0) {
                    cout << 1 << endl;
                    return 0;
                }
                n = n / i;
            }
            cout << i << endl;
            return 0;
        }
    }
    cout << n << endl;
}