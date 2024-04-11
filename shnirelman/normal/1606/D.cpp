//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 500 + 13;
const int M = 998244353;
const ld eps = 1e-6;
const int B = 300;
const int K = 400;
const int LOGN = 20;

/*
*/

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    }

    vector<pii> ord(n);
    for(int i = 0; i < n; i++) {
        ord[i] = {a[i][0], i};
    }

    sort(ord.begin(), ord.end());

    vector<vector<int>> b(n);
    for(int i = 0; i < n; i++) {
        b[i] = a[ord[i].s];
    }

    vector<vector<int>> upmx(n, vector<int>(m, 0)), upmn(n, vector<int>(m, INF)), dnmx(n, vector<int>(m, 0)), dnmn(n, vector<int>(m, INF));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            upmx[i][j] = (i == 0 ? b[i][j] : max(b[i][j], upmx[i - 1][j]));
            upmn[i][j] = (i == 0 ? b[i][j] : min(b[i][j], upmn[i - 1][j]));
        }
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            dnmx[i][j] = (i == n - 1 ? b[i][j] : max(b[i][j], dnmx[i + 1][j]));
            dnmn[i][j] = (i == n - 1 ? b[i][j] : min(b[i][j], dnmn[i + 1][j]));
        }
    }

    for(int i = 0; i < n - 1; i++) {
        if(b[i][0] == b[i + 1][0])
            continue;

        vector<int> prmx(m, 0), prmn(m, INF), sufmx(m, 0), sufmn(m, INF);

        prmx[0] = upmx[i][0];
        prmn[0] = dnmn[i + 1][0];
        for(int j = 1; j < m; j++) {
            prmx[j] = max(prmx[j - 1], upmx[i][j]);
            prmn[j] = min(prmn[j - 1], dnmn[i + 1][j]);
        }

        sufmx[m - 1] = dnmx[i + 1][m - 1];
        sufmn[m - 1] = upmn[i][m - 1];
        for(int j = m - 2; j >= 0; j--) {
            sufmx[j] = max(sufmx[j + 1], dnmx[i + 1][j]);
            sufmn[j] = min(sufmn[j + 1], upmn[i][j]);
        }

        for(int j = 0; j < m - 1; j++) {
            if(prmx[j] < prmn[j] && sufmx[j + 1] < sufmn[j + 1]) {
                cout << "YES" << '\n';
                vector<char> res(n);
                for(int k = 0; k < n; k++) {
                    res[ord[k].s] = (k <= i ? 'B' : 'R');
                }

                for(auto c : res)
                    cout << c;
                cout << ' ' << j + 1 << '\n';
                return;
            }
        }
    }

    cout << "NO" << '\n';
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}