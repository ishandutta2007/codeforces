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
    int n, m;
    cin >> n >> m;
    vector<int> maxm(n);
    int maxsumm = 0;
    REP(i, n) {
        maxm[i] = i / 2;
        maxsumm += maxm[i];
    }
    if(m > maxsumm) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> mm(n);
    REP(i, n) {
        mm[i] = min(m, maxm[i]);
        m -= mm[i];
    }
    vector<int> ans(n);
    ans[0] = 1;
    ans[1] = 2;
    int z = -1;
    FOR(i, 2, n) {
        if(mm[i] == 0) {
            if(ans[i-1] < 1e8) {
                z = ans[i-1] + 1;
                ans[i] = 1e8;
            } else {
                ans[i] = ans[i-1] + z;
            }
        } else {
            if(mm[i] == maxm[i]) {
                ans[i] = i+1;
            } else {
                ans[i] = ans[i-1] + ans[i-2*mm[i]];
            }
            
        }
    }
    REP(i, n) cout << ans[i] << (i!=n-1 ? " " : "");
    cout << endl;
}