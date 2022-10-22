#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(degug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 3e5 + 13;
const int LOGN = 30;
const int K = 22;
const int M = 1e9 + 7;
const int A = 26;

/*
2 3
1 2
*/

void solve(bool debug_out) {
    int n, m, r, c;
    cin >> n >> m >> r >> c;

    r--;
    c--;

    vector<string> s(n);
    for(int i = 0; i < n; i++)
        cin >> s[i];

    if(s[r][c] == 'B')
        cout << 0 << endl;
    else {
        bool fl1 = false, fl2 = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(s[i][j] == 'B') {
                    if(i == r || j == c)
                        fl1 = true;
                    else
                        fl2 = true;
                }
            }
        }

        cout << (fl1 ? 1 : (fl2 ? 2 : -1)) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve(true);
}