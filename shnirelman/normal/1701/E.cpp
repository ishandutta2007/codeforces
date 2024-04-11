#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 1e9 + 7;
const int N = 5000 + 13;
const int LOGN = 30;
const int L = 2001;

int pref[N][N], suf[N][N];

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            pref[i][j] = suf[i][j] = INF;
        }
    }

    string s, t;
    cin >> s >> t;

    pref[0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= m; j++) if(pref[i][j] < INF) {
            pref[i + 1][j] = min(pref[i + 1][j], pref[i][j] + 2);
            if(j < m && s[i] == t[j])
                pref[i + 1][j + 1] = min(pref[i + 1][j + 1], pref[i][j] + 1);
        }
    }

    suf[n][m] = 0;
    for(int i = n; i > 0; i--) {
        for(int j = m; j >= 0; j--) if(suf[i][j] < INF) {
            suf[i - 1][j] = min(suf[i - 1][j], suf[i][j] + 1);
            if(j > 0 && s[i - 1] == t[j - 1])
                suf[i - 1][j - 1] = min(suf[i - 1][j - 1], suf[i][j] + 1);
        }
    }

    int ans = INF;

    for(int i = 0; i <= m; i++) {
        ans = min(ans, suf[i][i]);
//        cout << i << ' ' << ans << endl;
        if(i < m && s[i] != t[i])
            break;
    }

//    cout << ans << endl;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i > 0 && j > 0 && s[i - 1] == t[j - 1])
                pref[i][j] = min(pref[i][j], pref[i - 1][j - 1]);

            if(pref[i][j] < INF)
                ans = min(ans, pref[i][j] + suf[i][j] + 1);
        }
    }

    cout << (ans < INF ? ans : -1) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}