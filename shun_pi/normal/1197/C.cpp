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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    int ans = a[n-1] - a[0];
    vector<int> b(n-1);
    REP(i, n-1) {
        b[i] = a[i+1] - a[i];
    }
    sort(b.begin(),b.end(),greater<int>());
    REP(i, k-1) {
        ans -= b[i];
    }
    cout << ans << endl;
}