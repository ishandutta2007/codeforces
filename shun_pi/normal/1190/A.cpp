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
    lint n, m, k;
    cin >> n >> m >> k;
    vector<lint> p(m);
    REP(i, m) cin >> p[i];
    lint ans = 0;
    lint page = -1;
    lint removed = 0;
    REP(i, m) {
        if(page == -1) {
            page = (p[i]-1-removed) / k;
        } else {
            if((p[i]-1-removed) / k != page) {
                ans++;
                removed = i;
                page = (p[i]-1-removed) / k;
            }
        }
    }
    cout << ans+1 << endl;
}