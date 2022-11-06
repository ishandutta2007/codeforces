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
  cout << (expr ? "YES" : "NO") << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    REP(t, T) {
        int n;
        cin >> n;
        vector<int> a(n);
        REP(i, n) cin >> a[i];
        vector<bool> va(n);
        va[0] = true;
        REP(i, n) if(a[i] > a[0]) va[i] = true;
        int ma = 0;
        IREP(i, n) {
            if(va[i]) {
                if(a[i] > ma) ma = a[i];
            } else {
                if(a[i] < ma) va[i] = true;
            }
        }
        bool flg = true;
        REP(i, n) if(!va[i])flg = false;
        yes(flg);
    }
}