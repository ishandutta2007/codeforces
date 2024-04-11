#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    REP(i, n) cin >> s[i];
    vector<string> t(m);
    REP(i, m) cin >> t[i];
    int Q;
    cin >> Q;
    REP(q, Q) {
        int y;
        cin >> y;
        cout << s[(y-1)%n] << t[(y-1)%m] << endl;
    }
}