#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

const int INF = (int)1e9 + 41;

void mxe(int &a, int b) {
    if (b > a) a = b;
}

void print(int a, int b, const vector<int> &res) {
    cout << a << ", " << b << ": ";
    for (int x : res) cout << (x == -INF ? -1 : x) << " ";
    cout << endl;
}

void solve() {
    map<pair<int, int>, vector<int>> dp;

    int n, k;
    cin >> n >> k;
    vector<bool> u((1 << n), false);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        u[x - 1] = true;
    }
    
    for (int lv = 0; lv < n; lv++) {
        for (int a = 0; a < (1 << n); a += (2 << lv)) {
            int b = a + (2 << lv);
            vector<int> res(4, -INF);
            if (lv == 0) {        
                if (u[a] && u[b - 1]) res[3] = 1;
                else if (u[a] || u[b - 1]) res[2] = res[1] = 1;
                else res[0] = 0;
                dp[make_pair(a, b)] = res;
                //print(a, b, res);
                continue;
            }

            auto r1 = dp[make_pair(a, (a + b) / 2)];
            auto r2 = dp[make_pair((a + b) / 2, b)];

            for (int i = 0; i < 4; i++) {
                if (r1[i] == -INF) continue;
                int a = i / 2;
                int c = i % 2;
                for (int j = 0; j < 4; j++) {
                    if (r2[j] == -INF) continue;
                    
                    int b = j / 2;
                    int d = j % 2;

                    int cur = r1[i] + r2[j] + __builtin_popcount(i | j);

                    for (int msk = 0; msk < 8; msk++) {
                        int aa = a, bb = b, cc = c, dd = d;
                        if (msk & 1) swap(aa, bb);
                        if (msk & 2) swap(cc, dd);
                        if (msk & 4) swap(bb, cc);
                        mxe(res[aa * 2 + cc], cur + (bb + cc >= 1 ? 1 : 0));
                    }
                }
            }
            dp[make_pair(a, b)] = res;
            //print(a, b, res);
        }
    }

    auto res = dp[make_pair(0, (1 << n))];
    int ans = 0;

    for (int i = 0; i < 4; i++) {
        ans = max(ans, res[i] + (i == 0 ? 0 : 1));
    }

    cout << ans << "\n";    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    //cout << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    int T = 4;
    for (int i = 1; i < T; i++) solve();    
#endif
}