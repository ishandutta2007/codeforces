#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
int main()
{
    int T;
    cin >> T;
    REP(t, T) {
        int n;
        cin >> n;
        vector<tuple<int, int>> a(n);
        REP(i, n) {
            int aa;
            cin >> aa;
            a[i] = make_tuple(aa, i);
        }
        vector<tuple<int, int>> b(n);
        REP(i, n) {
            int bb;
            cin >> bb;
            b[i] = make_tuple(bb, i);
        }
        sort(a.begin(), a.end(), [](auto const &a, auto const &b) { return get<0>(a) < get<0>(b); });
        sort(b.begin(), b.end(), [](auto const &a, auto const &b) { return get<0>(a) < get<0>(b); });
        REP(i, n) cout << get<0>(a[i]) << (i!=n-1 ? " " : "");
        cout << endl;
        REP(i, n) cout << get<0>(b[i]) << (i!=n-1 ? " " : "");
        cout << endl;
    }
}