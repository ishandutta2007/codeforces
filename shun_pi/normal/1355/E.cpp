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
    lint N, A, R, M;
    cin >> N >> A >> R >> M;
    if(M > A+R) M = A+R;
    vector<lint> h(N);
    lint hsum = 0;
    REP(i, N) {
        cin >> h[i];
        hsum += h[i];
    }
    sort(ALL(h));
    lint l = h[0]-1;
    lint r = h[N-1]+1;
    lint m;
    while(r-l > 1) {
        m = (l+r) / 2;
        lint rem1 = m*N - hsum;
        lint ans1 = rem1 >= 0 ? rem1*A : -rem1*R;
        lint diff1 = 0;
        REP(i, N) {
            diff1 += abs(h[i]-m);
        }
        diff1 = (diff1 - abs(rem1)) / 2;
        ans1 += diff1 * M;
        lint rem2 = (m+1)*N - hsum;
        lint ans2 = rem2 >= 0 ? rem2*A : -rem2*R;
        lint diff2 = 0;
        REP(i, N) {
            diff2 += abs(h[i]-m-1);
        }
        diff2 = (diff2 - abs(rem2)) / 2;
        ans2 += diff2 * M;
        //cout << m << " " << ans1 << " " << ans2 << endl;
        if(ans2 >= ans1) {
            r = m;
        } else {
            l = m;
        }
    }
    lint rem = r*N - hsum;
    lint ans = rem >= 0 ? rem*A : -rem*R;
    lint diff = 0;
    REP(i, N) {
        diff += abs(h[i]-r);
    }
    diff = (diff - abs(rem)) / 2;
    ans += diff * M;
    cout << ans << endl;

}