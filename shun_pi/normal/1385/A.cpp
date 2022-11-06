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
    while(T--) {
        int x, y, z;
        cin >> x >> y >> z;
        int ma = max(max(x, y), z);
        if(ma == x && ma == y) {
            cout << "YES" << "\n";
            cout << ma << " " << z << " " << 1 << "\n";
        } else if(ma == x && ma == z) {
            cout << "YES" << "\n";
            cout << y << " " << ma << " " << 1 << "\n";
        } else if(ma == y && ma == z) {
            cout << "YES" << "\n";
            cout << x << " " << 1 << " " << ma << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}