#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
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
    int T;
    cin >> T;
    REP(t, T) {
        string S;
        cin >> S;
        lint l = 0;
        lint r = 0;
        lint ans = S.size()+2;
        vector<int> cnt(3);
        while(true) {
            bool flg = true;
            REP(i, 3) {
                if(cnt[i] == 0) {
                    flg = false;
                    break;
                }
            }
            if(flg) {
                if(r-l < ans) ans = r-l;
                cnt[S[l]-'1']--;
                l++;
                continue;
            }
            if(r == S.size()) break;
            cnt[S[r]-'1']++;
            r++;
        }
        if(ans == S.size()+2) {
            cout << 0 << "\n";
        } else {
            cout << ans << endl;
        }
    }
}