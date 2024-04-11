#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<lint, lint>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lint k;
    cin >> k;
    vector<int> cnt(10, 1);
    while(true) {
        bool flg = false;
        REP(i, 10) {
            lint tmp = 1;
            REP(j, 10) tmp *= cnt[j];
            if(tmp >= k) {
                flg = true;
                break;
            }
            cnt[i]++;
            
        }
        if(flg) break;
    }
    string c = "codeforces";
    string ans = "";
    REP(i, 10) {
        REP(j, cnt[i]) {
            ans += c[i];
        }
    }
    cout << ans << endl;
    
}