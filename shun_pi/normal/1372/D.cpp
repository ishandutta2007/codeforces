#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using P = pair<int, int>;
using PL = pair<lint, lint>;
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
    lint asum = 0;
    REP(i, n) asum += a[i];
    lint sum = 0;
    lint ans = 1e18;
    for(int i=0; i<n-2; i+=2) sum += a[i];
    REP(k, n) {
        int idx1 = (n-3-k*2+2*n) % n;
        int idx2 = (idx1 + 1) % n;
        sum += a[idx2];
        sum -= a[idx1];
        if(sum < ans) ans = sum;
    }
    cout << asum - ans << endl;
}