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
        lint n, s;
        cin >> n >> s;
        vector<lint> a(n);
        REP(i, n) cin >> a[i];
        lint sum = 0;
        REP(i, n) {
            sum += a[i];
        }
        if(sum <= s) {
            cout << 0 << endl;
            continue;
        }
        lint max = 0;
        sum = 0;
        lint idx = 0;
        REP(i, n) {
            sum += a[i];
            lint tmpidx = idx;
            if(a[i] > max) {
                max = a[i];
                tmpidx = i+1;
            }
            if(sum - max > s) break;
            idx = tmpidx;
        }
        cout << idx << endl;
    }
}