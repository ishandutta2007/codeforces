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
    int T;
    cin >> T;
    REP(t, T) {
        vector<int> a(3);
        REP(i, 3) cin >> a[i];
        sort(a.begin(), a.end(),
            [](auto const &a, auto const &b) { return a > b; });
        if(a[0] >= a[1] + a[2] + 2) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}