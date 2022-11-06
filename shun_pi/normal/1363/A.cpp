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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        REP(i, n) cin >> a[i];
        int even = 0;
        int odd = 0;
        REP(i, n) {
            if(a[i]%2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        if(odd%2 == 0) odd--;
        if(odd <= 0) {
            cout << "No" << "\n";
            continue;
        }
        x -= odd;
        while(x < 0) x += 2;
        yes(even >= x);
    }
}