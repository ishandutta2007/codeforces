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
        lint n;
        cin >> n;
        vector<lint> ans;
        lint now = 1;
        while(true) {
            lint div = n / now;
            ans.push_back(div);
            if(div == 0) break;
            now = (n / div) + 1;
        }
        cout << ans.size() << endl;
        IREP(i, ans.size()) cout << ans[i] << (i!=0 ? " " : "");
        cout << endl;
    }
}