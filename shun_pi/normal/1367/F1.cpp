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
        int n;
        cin >> n;
        vector<int> a(n);
        REP(i, n) cin >> a[i];
        vector<int> at(a);
        sort(ALL(at));
        map<int, int> mp;
        REP(i, n) mp[at[i]] = i;
        REP(i, n) a[i] = mp[a[i]];
        int ans = n;
        REP(i, n) {
            int last = a[i];
            int cnt = 1;
            FOR(j, i+1, n) {
                if(a[j] == last+1) {
                    cnt++;
                    last++;
                }
            }
            if(a[i] + (n-last-1) < ans) ans = a[i] + (n-last-1);
        }
        cout << ans << "\n";
    }
}