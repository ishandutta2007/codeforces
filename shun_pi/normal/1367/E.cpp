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
    int T;
    cin >> T;
    REP(t, T) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> cnt(26);
        REP(i, s.size()) cnt[s[i]-'a']++;
        int ans = 0;
        REP(i, 26) if(cnt[i] > ans) ans = cnt[i];
        FOR(i, 1, n+1) {
            if(k%i == 0) {
                for(int j=1; j*i<=n; j++) {
                    int sum = 0;
                    REP(l, 26) sum += cnt[l] / j;
                    if(sum >= i && i*j > ans) ans = i*j;
                }
            }     
        }
        
        cout << ans << "\n";
    }
}