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
  cout << (expr ? "Yes" : "No") << endl;
}
int main()
{
    int n;
    cin >> n;
    vector<lint> a(n);
    REP(i, n) cin >> a[i];
    lint ans = 0;
    lint left = 0;
    lint sum = 0;
    map<lint, lint> mp;
    mp[0] = 1;
    REP(i, n) {
        sum += a[i];
        if(mp[sum] >= 1) {
            left = max(left, mp[sum]);
            
        }
        mp[sum] = i+2;
        ans += i - (left-1);
    }
    cout << ans << endl;
}