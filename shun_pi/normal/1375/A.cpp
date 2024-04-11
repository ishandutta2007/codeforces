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
    int T;
    cin >> T;
    REP(t, T) {
        int n;
        cin >> n;
        vector<int> a(n);
        REP(i, n) cin >> a[i];
        REP(i, n) if(a[i] < 0) a[i] = -a[i];
        REP(i, n-1) {
            int g = 0;
            int l = 0;
            REP(j, n-1) {
                if(a[j+1] - a[j] > 0) g++;
                else if(a[j+1] - a[j] < 0) l++;
            }
            if(g > (n-1)/2 && a[i+1] - a[i] > 0) {
                if(a[i+1] + a[i] < 0) a[i] = -a[i];
                else if(-a[i+1] - a[i] < 0 ) {
                    a[i+1] = -a[i+1];
                    i++;
                }
            }
            if(l > (n-1)/2 && a[i+1] - a[i] < 0) {
                if(a[i+1] + a[i] > 0) a[i] = -a[i];
                else if(-a[i+1] - a[i] > 0 ) {
                    a[i+1] = -a[i+1];
                    i++;
                }
            }
        }
        REP(i, n) cout << a[i] << (i!=n-1 ? " " : "");
        cout << "\n";
    }
}