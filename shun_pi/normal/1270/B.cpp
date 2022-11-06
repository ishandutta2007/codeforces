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
        int n;
        cin >> n;
        vector<lint> a(n);
        REP(i, n) cin >> a[i];
        bool flg = false;
        FOR(i, 1, n) {
            if(abs(a[i] - a[i-1]) >= 2) {
                cout << "YES" << endl;
                cout << i << " " << i+1 << endl;
                flg = true;
                break;
            }
        }
        if(!flg) cout << "NO" << endl;
    }
}