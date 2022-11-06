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
    lint n, x;
    cin >> n >> x;
    vector<lint> d(n*2);
    REP(i, n) cin >> d[i];
    FOR(i, n, 2*n) d[i] = d[i-n];
    vector<lint> S(n*2);
    S[0] = d[0];
    FOR(i, 1, 2*n) S[i] = S[i-1] + d[i];
    vector<lint> SS(n*2);
    SS[0] = d[0]*(d[0]+1)/2;
    FOR(i, 1, 2*n) SS[i] = SS[i-1] + d[i]*(d[i]+1)/2;
    lint ans = 0;
    FOR(i, 1, 2*n) {
        int l = i-1;
        int r = 2*n;
        while(r-l  > 1) {
            int m = (l+r) / 2;
            if(S[m]-S[i-1] >= x) {
                r=m;
            } else {
                l=m;
            }
        }
        if(r == 2*n) break;
        FOR(j, r, 2*n) {
            lint rem = S[j]-S[i-1]-x;
            if(rem > d[j]+d[i]) break;
            lint sum = SS[j]-SS[i-1];
            if(d[i] <= d[j]) {
                sum -= min(rem, d[i])*(min(rem,d[i])+1)/2;
                rem -= d[i];
                if(rem > 0) {
                    sum -= rem*(rem+1)/2 + (d[j]-rem)*rem;
                }
            } else {
                sum -= min(rem, d[j])*(min(rem,d[j])+1)/2;
                rem -= d[j];
                if(rem > 0) {
                    if(rem >= d[j]) {
                        sum -= d[j]*(d[j]+1)/2;
                        rem -= d[j];
                        sum -= rem*(rem+1)/2 + d[j]*rem;
                    } else {
                        sum -= rem*(rem+1)/2 + (d[j]-rem)*rem;
                    }
                }
            }
            if(sum > ans) ans = sum;
        }
        
    }
    cout << ans << endl;

}