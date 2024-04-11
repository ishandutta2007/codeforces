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
    int t;
    cin >> t;
    REP(i, t) {
        int r, g, b;
        cin >> r >> g >> b;
        if (r >= g && r >= b) {
            r = min(r , g+b);
        } else if(g >= r && g >= b) {
            g = min(g , r+b);
        } else {
            b =  min(b, r+g);
        }
        cout << (r+g+b)/2 << endl;
    }
}