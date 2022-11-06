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
  cout << (expr ? "YES" : "NO") << endl;
}
int main()
{
    int T;
    cin >> T;
    REP(t, T) {
        int n;
        cin >> n;
        vector<int> a(n);
        REP(i, n) cin >> a[i];
        vector<int> b(n);
        REP(i, n) cin >> b[i];
        bool canplus = false;
        bool canminus = false;
        bool flg = true;
        REP(i, n) {
            if(a[i] == b[i] || (a[i] > b[i] && canminus) || (a[i] < b[i] && canplus)) {
                
            } else {
                flg = false;
                break;
            }
            if(a[i] == 1) canplus = true;
            if(a[i] == -1) canminus = true;
        }
        yes(flg);
    }
}