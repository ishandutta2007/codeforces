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
    vector<lint> a(n);
    REP(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    lint can = 0;
    bool flg = false;
    REP(i, n) {
        if(i != 0 && a[i] == a[i-1]) {
            if(flg) {
                cout << "cslnb" << endl;
                return 0;
            }
            if(i == 1 && a[i] == 0) {
                cout << "cslnb" << endl;
                return 0;
            } else if(i != 1 && a[i-1] - a[i-2] <= 1) {
                cout << "cslnb" << endl;
                return 0;
            }
            flg = true;
        }
        can += a[i] - i;
    }
    if(can % 2 == 0) {
        cout << "cslnb" << endl;
    } else {
        cout << "sjfnb" << endl;
    }
}