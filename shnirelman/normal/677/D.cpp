#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li
#define err if(debug_out)cout

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 300 + 13;
const int LOGN = 20;
const int K = 12;
const int M = 1e9 + 7;
//const int M = 998244353;
const int A = 26;
const ld eps = 1e-8;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};

mt19937 rnd(45768);

int mul(int a, int b) {
    return a * 1ll * b % M;
}

/*
*/

int a[N][N];
li dp[N][N];
vector<pii> pos[N * N];
int d[N][N];
bool used[N][N];
vector<pii> dpos[N * N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, p;
    cin >> n >> m >> p;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j]--;

            pos[a[i][j]].emplace_back(i, j);
            dp[i][j] = (a[i][j] == 0 ? i + j : INF64);
        }
    }

    for(int ind = 0; ind < p - 1; ind++) {
        int x = pos[ind].size(), y = pos[ind + 1].size();
        if(x * y <= 300000) {
//        if(x * y <= 1) {
            for(pii pos1 : pos[ind])
                for(pii pos2 : pos[ind + 1]) {
                    dp[pos2.f][pos2.s] = min(dp[pos2.f][pos2.s], dp[pos1.f][pos1.s] + abs(pos1.f - pos2.f) + abs(pos1.s - pos2.s));
                }
        } else {
//            set<pair<int, pii>> st;
            li mn = INF64;
            for(pii pos1 : pos[ind]) {
                mn = min(mn, dp[pos1.f][pos1.s]);
            }

            for(int d1 = 0; d1 < n * m; d1++)
                dpos[d1].erase(dpos[d1].begin(), dpos[d1].end());

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
//                    d[i][j] = (a[i][j] == ind ? dp[i][j] - mn : INF);
//                    d[i][j] = (a[i][j] == ind ? dp[i][j] - mn : INF);
                    if(a[i][j] == ind) {
                        d[i][j] = dp[i][j] - mn;
                        dpos[d[i][j]].emplace_back(i, j);
                        used[i][j] = true;
                    } else {
                        d[i][j] = INF;
                        used[i][j] = false;
                    }
//                    st.emplace(d[i][j], pii(i, j));
                }
            }

            for(int d1 = 0; d1 < n * m; d1++) {
                for(pii pos1 : dpos[d1]) {
                    int i = pos1.f, j = pos1.s;
//                    cout << "bfs " << d1 << ' ' << i << ' ' << j << endl;

                    if(a[i][j] == ind + 1)
                        dp[i][j] = mn + d1;

                    for(int k = 0; k < 4; k++) {
                        int i1 = i + di[k], j1 = j + dj[k];
                        if(i1 < 0 || i1 >= n || j1 < 0 || j1 >= m || used[i1][j1])
                            continue;

                        d[i1][j1] = d1 + 1;
                        dpos[d1 + 1].emplace_back(i1, j1);
                        used[i1][j1] = true;
                    }
                }
            }

//            while(!st.empty()) {
//                int i = st.begin()->s.f;
//                int j = st.begin()->s.s;
//                st.erase(st.begin());
//
//                if(a[i][j] == ind + 1)
//                    dp[i][j] = d[i][j] + mn;
//
//                for(int k = 0; k < 4; k++) {
//                    int i1 = i + di[k], j1 = j + dj[k];
//                    if(i1 < 0 || i1 >= n || j1 < 0 || j1 >= m)
//                        continue;
//                    if(d[i1][j1] > d[i][j] + 1) {
//                        st.erase({d[i1][j1], pii(i1, j1)});
//                        d[i1][j1] = d[i][j] + 1;
//                        st.insert({d[i1][j1], pii(i1, j1)});
//                    }
//                }
//            }
        }

//        cout << endl;
//        for(int i = 0; i < n; i++) {
//            for(int j = 0; j < m; j++)
//                cout << dp[i][j] << ' ';
//            cout << endl;
//        }
    }

    cout << dp[pos[p - 1][0].f][pos[p - 1][0].s] << endl;
}