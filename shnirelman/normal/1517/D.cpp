#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 513;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};

/*

*/

mt19937 rnd(3666);

vector<pii> g[N * N];

int n, m, k;

int get(int i, int j) {
    return i * m + j;
}

int dp[K][N * N];

int solve(int vi, int vj) {
    if(k % 2 != 0)
        return INF;

    dp[0][get(vi, vj)] = 0;



    for(int ind = 0; ind < k / 2; ind++) {
        for(int di = max(-vi, -ind); di <= min(n - vi - 1, ind); di++) {
            for(int dj = max(-vj, -(ind - abs(di))); dj <= min(m - vj, ind - abs(di)); dj++) {
                int v = get(vi + di, vj + dj);
                if(dp[ind][v] < INF) {
                    for(auto p : g[v]) {
                        dp[ind + 1][p.f] = min(dp[ind + 1][p.f], dp[ind][v] + p.s);
                    }
                }

                dp[ind][v] = INF;
            }
        }
//        for(int i = lfi; i < rgi; i++) {
//            for(int j = lfj; j < rgj; j++) {
//                int v = get(i, j);
//                if(dp[ind][v] < INF)
//                    for(auto p : g[v])
//                        dp[ind + 1][p.f] = min(dp[ind + 1][p.f], dp[ind][v] + p.s);
//
//                dp[ind][v] = INF;
//            }
//        }
//
//        for(int i = lfi; i < rgi; i++) {
//            for(int j = lfj; j < rgj; j++)  {
//                int v = get(i, j);
//                dp[v] = dp1[v];
//                dp1[v] = INF;
//            }
//        }
    }

    int res = INF;

    int lfi = max(0, vi - 21), rgi = min(n, vi + 22);
    int lfj = max(0, vj - 21), rgj = min(m, vj + 22);

    for(int i = lfi; i < rgi; i++)
        for(int j = lfj; j < rgj; j++) {
            int v = get(i, j);
            res = min(res, dp[k / 2][v] * 2);
            dp[k / 2][v] = INF;
        }


    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m - 1; j++) {
            int x;
            cin >> x;

            int v = get(i, j);
            int u = get(i, j + 1);

            g[v].emplace_back(u, x);
            g[u].emplace_back(v, x);
        }
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m; j++) {

            int x;
            cin >> x;

            int v = get(i, j);
            int u = get(i + 1, j);

            g[v].emplace_back(u, x);
            g[u].emplace_back(v, x);
        }
    }

    for(int j = 0; j < K; j++)
        for(int i = 0; i < N * N; i++) {
            dp[j][i] = INF;
        }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int res = solve(i, j);

            cout << (res < INF ? res : -1) << ' ';
//            return 0;
        }
        cout << endl;
    }
}