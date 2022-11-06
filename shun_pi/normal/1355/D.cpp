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
    lint N, S;
    cin >> N >> S;
    if(S < N*2) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    lint num = S / N;
    lint rem = S % N;
    vector<lint> ans;
    REP(i, rem) ans.push_back(num+1);
    REP(i, N-rem) ans.push_back(num);
    REP(i, N) cout << ans[i] << (i!=N-1 ? " " : "");
    cout << "\n";
    cout << 1 << endl;
}