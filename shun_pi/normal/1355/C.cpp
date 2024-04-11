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
    lint A, B, C, D;
    cin >> A >> B >> C >> D;
    vector<lint> xpy(B+C+2);
    FOR(x, A, B+1) {
        xpy[x+B]++;
        xpy[x+C+1]--;
    }
    REP(i, B+C+1) xpy[i+1] += xpy[i];
    IREP(i, B+C+1) xpy[i] += xpy[i+1];
    lint ans = 0;
    FOR(z, C, D+1) {
        if(z <= B+C) {
            ans += xpy[z+1];
        }
        
    }
    cout << ans << endl;
}