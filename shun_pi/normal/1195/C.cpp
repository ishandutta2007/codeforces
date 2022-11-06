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
    int n;
    cin >> n;
    vector<lint> h1(n);
    REP(i, n) cin >> h1[i];
    vector<lint> h2(n);
    REP(i, n) cin >> h2[i];
    if(n == 1) {
        cout << max(h1[0], h2[0]) << endl;
    } else {
        h1[1] += h2[0];
        h2[1] += h1[0];
        FOR(i, 2, n) {
            h1[i] += max(h2[i-1], h2[i-2]);
            h2[i] += max(h1[i-1], h1[i-2]);
        }
        cout << max(h1[n-1], h2[n-1]) << endl;
    }
}