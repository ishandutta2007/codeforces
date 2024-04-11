#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb subnb
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50, M = (int)1e7 + 50;
const int K = 22, INF = (int)1e9;

int n, k;
int p[M];
int dp[N][K], a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    iota(p, p + M, 0);
    rep(i, 2, M) {
        if(p[i] != i) continue;
        for (int j = i * 2; j < M; j += i) p[j] = i;
    }
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> k;
        rep(i, 1, n + 1) cin >> a[i];
        map<vi, int> la;
        auto las = deque<int>(k + 1, 0);
        rep(i, 1, n + 1) {
            vi facs;
            int x = a[i];
            while(x > 1) {
                int v = p[x], c = 0;
                while(x % v == 0) x /= v, c++;
                if(c & 1) facs.push_back(v);
            }
            sort(all(facs));
//            cout << a[i] << ": ";
//            for (int x : facs) cout << x << " ";
//            cout << endl;
            int &r = la[facs];
            if(r) {
                las.push_front(r);
                for (int j = 0; j + 1 < sz(las); j++) {
                    if(las[j] < las[j + 1]) swap(las[j], las[j + 1]);
                    else break;
                }
                las.pop_back();
            }
            r = i;

            fill(dp[i], dp[i] + K, INF);
            rep(j, 0, k + 1) {
                rep(tk, 0, j + 1) {
//                    cout << tk << ", " << i << " " << las[tk] + 1 << endl;
                    dp[i][j] = min(dp[i][j], dp[las[tk]][j - tk] + 1);
                }
            }
        }
        int res = INF;
        rep(j, 0, k + 1) res = min(res, dp[n][j]);
        cout << res << '\n';
    }




}