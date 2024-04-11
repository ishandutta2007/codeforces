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
    lint n;
    cin >> n;
    vector<lint> a(n);
    REP(i, n) cin >> a[i];
    vector<int> cnt(20);
    REP(i, n) {
        REP(j, 20) {
            if((a[i]>>j&1)==1) cnt[j]++;
        }
    }
    vector<lint> ans(n);
    REP(k, 20) {
        REP(i, cnt[k]) {
            ans[i] += 1<<k;
        }
    }
    lint sum = 0;
    REP(i, n) sum += ans[i]*ans[i];
    cout << sum << endl;
}