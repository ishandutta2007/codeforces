#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 905;

int n, m;
int a[N][N];
int cnt[N][2];
int f[N];

int find(int i) {return f[i] == i ? i : f[i] = find(f[i]);}
void unite(int i, int j) {
    f[find(i)] = find(j);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        for(int i = 0; i < n * m; i++) f[i] = i;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int i2 = i; i2 < n; i2++) {
                    for(int j2 = j; j2 < m; j2++) {
                        if(i + j == (n - 1 - i2) + (m - 1 - j2)) unite(i * m + j, i2 * m + j2);
                    }
                }
            }
        }
        rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];
        memset(cnt, 0, sizeof(cnt));
        rep(i, 0, n) rep(j, 0, m) {
            cnt[find(i * m + j)][a[i][j]]++;
        }
        int res = 0;
        for(int i = 0; i < N; i++) res += min(cnt[i][0], cnt[i][1]);
        cout << res << '\n';
    }

}