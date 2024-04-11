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
    lint u, v;
    cin >> u >> v;
    if(u == 0 && v == 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<lint> ans(60);
    REP(i, 60) {
        if(((u >> i) & 1) == ((v >> i) & 1)) {
            if(((u >> i) & 1) == 1) {
                ans[i]++;
            }
        } else {
            if(i == 0) {
                cout << -1 << endl;
                return 0;
            }
            if(((u >> i) & 1) == 1) {
                ans[i]++;
                v -= pow(2, i+1);
                if(v < 0) {
                    cout << -1 << endl;
                    return 0;
                }
            }
            ans[i-1] += 2;
        }
    }
    int s = 1;
    REP(i, 60) {
        if(ans[i] > s) s = ans[i];
    }
    vector<lint> ans2(s);
    REP(i, 60) {
        REP(j, ans[i]) {
            ans2[j] += pow(2, i);
        }
    }
    cout << ans2.size() << endl;
    REP(i, ans2.size()) cout << ans2[i] << (i!=ans2.size()-1 ? " " : "");
    cout << endl;
}