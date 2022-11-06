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
    int T;
    cin >> T;
    REP(t, T) {
        lint n, m;
        cin >> n >> m;
        lint zeros = n - m;
        lint a = zeros / (m+1);
        lint b = zeros % (m+1);
        lint ans = n*(n+1)/2 - (m+1-b)*a*(a+1)/2 - b*(a+1)*(a+2)/2;
        cout << ans << endl; 
    }
}