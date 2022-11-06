#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    REP(t, T) {
        lint n, l, r;
        cin >> n >> l >> r;
        lint step = 0;
        vector<lint> ans;
        FOR(i, 2, n+1) {
            step++;
            if(step >= l) ans.push_back(1);
            if(step == r) {
                break;
            }
            step++;
            if(step >= l) ans.push_back(i);
            if(step == r) {
                break;
            }
        }
        if(step == r) {
            REP(i, ans.size()) cout << ans[i] << (i!=ans.size()-1 ? " " : "");
            cout << "\n";
            continue;
        }
        lint now = 2;
        while(true) {
            if(now == n) break;
            if(step+(2*(n-now)) < l) {
                step += 2*(n-now);
            } else {
                bool flg = false;
                FOR(i, now+1, n+1) {
                    step++;
                    if(step >= l) ans.push_back(now);
                    if(step == r) {
                        flg = true;
                        break;
                    }
                    step++;
                    if(step >= l) ans.push_back(i);
                    if(step == r) {
                        flg = true;
                        break;
                    }
                }
                if(flg) break;
            }
            now++;
            
        }
        if(step < r) ans.push_back(1);
        REP(i, ans.size()) cout << ans[i] << (i!=ans.size()-1 ? " " : "");
        cout << "\n";
        
    }
}