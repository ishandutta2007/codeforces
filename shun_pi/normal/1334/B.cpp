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
    int T;
    cin >> T;
    REP(t, T) {
        lint n, x;
        cin >> n >> x;
        vector<lint> a(n);
        REP(i, n) cin >> a[i];
        sort(a.begin(), a.end(), greater<lint>());
        if(a[0] < x) {
            cout << 0 << endl;
            continue;
        }
        REP(i, n-1) {
            a[i+1] += a[i];
        }
        int l = 0;
        int r = a.size()-1;
        int m = (l+r) / 2;
        while(l <= r) {
            if(a[m] / (m+1) >= x) {
                l = m+1;
            } else {
                r = m-1;
            }
            if(m == (l+r)/2) break;
            m = (l+r) / 2;
        }
        cout << (m+1) << "\n";
    }
}