#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 100005;
int t, n, res, cnt;
int all, c1, c2;
string sa, sb;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> sa >> sb;
        all = 0, c1 = 0, c2 = 0;
        REP(i, 0, n) all += (sa[i] != sb[i]), c1 += sa[i] - '0', c2 += sb[i] - '0';
        if (c1 == 0) {
            cout << (all ? "-1\n" : "0\n");
            continue;
        }
        if (c1 != c2 || all&1) res = 0x3c3c3c3c;
        else res = all;

        cnt = 0;
        REP(i, 0, n) if (sa[i] == sb[i] && sa[i] == '1') cnt = 1;
        c1 = n + 1 - c1;
        if (!cnt) all = n - all + 1;
        else all = n - all - 1;

        if (c1 != c2 || all&1); else res = min(res, all + 1);
        if (res == 0x3c3c3c3c) res = -1;
        cout << res << '\n';
    }
}