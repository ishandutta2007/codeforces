#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=l; i<=r; ++i)
#define REP(i,l,r) for(int i=l; i<r; ++i)
#define FORD(i,r,l) for(int i=r; i>=l; --i)
#define REPD(i,r,l) for(int i=r-1; i>=l; --i)
using namespace std;
const int N = 105;
int t, m, n, k, all, each, cnt_each, Q[62];
string s[N];
char ans[N][N];

void Init() {
    int d = 0;
    FOR(i, '0', '9') Q[d++] = (char)i;
    FOR(i, 'a', 'z') Q[d++] = (char)i;
    FOR(i, 'A', 'Z') Q[d++] = (char)i;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Init();
    cin >> t;
    while (t--) {
        all = 0;
        cin >> m >> n >> k;
        REP(i, 0, m) {
            cin >> s[i];
            for(char c : s[i]) all += (c == 'R');
        }
        each = all / k;
        cnt_each = k - all % k;
        int x = 0, y = 0;
        REP(i, 0, k) {
            int w = each;
            if (!cnt_each) ++w; else --cnt_each;
            do {
                ans[x][y] = Q[i];
                w -= (s[x][y] == 'R');
                y += (x&1 ? -1 : 1);
                if (y < 0) ++x, ++y;
                if (y == n) ++x, --y;
            } while (w > 0);
            if (w < 0) ++cnt_each;
        }
        while (x != m) {
            ans[x][y] = Q[k - 1];
            y += (x&1 ? -1 : 1);
            if (y < 0) ++x, ++y;
            if (y == n) ++x, --y;
        };

        REP(i, 0, m) {
            REP(j, 0, n) cout << ans[i][j];
            cout << '\n';
        }
    }
}