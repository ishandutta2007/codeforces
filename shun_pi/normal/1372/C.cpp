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
        REP(i, n) {
            cin >> a[i];
            a[i]--;
        }
        bool flg = true;
        REP(i, n) {
            if(a[i] != i) {
                flg = false;
                break;
            }
        }
        if(flg) {
            cout << 0 << "\n";
            continue;
        }
        int idx = -1;
        flg = true;
        REP(i, n) {
            if(a[i] != i) {
                if(idx == -1 || i == idx + 1) idx = i;
                else {
                    flg = false;
                    break;
                }
            }
        }
        if(flg) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }
}