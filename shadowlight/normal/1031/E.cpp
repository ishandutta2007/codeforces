#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;
const int M = 15;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    srand(time(0));
    vector <vector <int> > dp(M + 1);
    vector <vector <pair <int, int> > > nxt(M + 1);
    for (int m = 0; m <= M; m++) {
        int N = (1 << m);
        dp[m].resize(N, INF);
        nxt[m].resize(N);
        queue <int> q;
        if (m < M) {
            q.push(0);
            dp[m][0] = 0;
        } else {
            for (int i = 0; i < 8; i++) {
                q.push(i << 12);
                dp[M][i << 12] = 0;
            }
        }
        while (!q.empty()) {
            int mask = q.front();
            q.pop();
            for (int a = 0; a < m; a++) {
                for (int k = 1; k < m; k++) {
                    int b = a + k, c = a + 2 * k;
                    if (c >= m) break;
                    int mask1 = mask;
                    mask1 ^= (1 << a);
                    mask1 ^= (1 << b);
                    mask1 ^= (1 << c);
                    if (dp[m][mask1] != INF) continue;
                    dp[m][mask1] = dp[m][mask] + 1;
                    nxt[m][mask1] = {a, k};
                    q.push(mask1);
                }
            }
        }
    }
    int n;
    cin >> n;
    vector <int> all(n);
    for (int i = 0; i < n; i++) {
        cin >> all[i];
    }
//    int n = 1000;
//    vector <int> all(n);
//    for (int i = 0; i < n; i++) {
//        all[i] = rand() % 2;
//    }
    if (n < 15) {
        int mask = 0;
        for (int i = n - 1; i >= 0; i--) {
            mask = mask * 2 + all[i];
        }
        if (dp[n][mask] == INF) {
            cout << "NO\n";
            return 0;
        }
        cout << "YES\n";
        cout << dp[n][mask] << "\n";
        while (mask) {
            int a = nxt[n][mask].first, k = nxt[n][mask].second;
            mask ^= (1 << a);
            mask ^= (1 << (a + k));
            mask ^= (1 << (a + 2 * k));
            cout << a + 1 << " " << a + 1 + k << " " << a + 1 + 2 * k << "\n";
        }
        return 0;
    }
    cout << "YES\n";
    vector <pair <int, int> > res;
    for (int i = 0, sz = M, fl = false; !fl; i += 12) {
        if (i >= n - 14) {
            sz = 14;
            i = n - 14;
            fl = true;
        }
        int mask = 0;
        for (int j = sz - 1; j >= 0; j--) {
            mask = mask * 2 + all[i + j];
        }
        assert(dp[sz][mask] != INF);
        while (dp[sz][mask]) {
            int a = nxt[sz][mask].first, k = nxt[sz][mask].second;
            int b = a + k, c = a + 2 * k;
            all[i + a] ^= 1;
            all[i + b] ^= 1;
            all[i + c] ^= 1;
            mask ^= (1 << a);
            mask ^= (1 << b);
            mask ^= (1 << c);
            res.push_back({i + a, k});
        }
    }
    for (int i = 0; i < n; i++) {
        assert(!all[i]);
    }
    cout << res.size() <<"\n";
    for (auto p : res) {
        int a = p.first, k = p.second;
        cout << a + 1 << " " << a + k + 1 << " " << a + 2 * k + 1 << "\n";
    }
}