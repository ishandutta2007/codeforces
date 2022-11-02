#include <bits/stdc++.h>
using namespace std;
#define N 200020
#define K 26
#define inf 1000000007
#define eps 1e-7
#define pi acos(-1)
#define gc getchar
#define pc putchar
#define pb push_back

typedef pair <int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int t, n, m, k, cnt[K];
bool vis[N];
char s[N];

int solve() {
    int ans = inf;
    for (int i = 0; i < n; i ++) vis[i] = 0;
    vis[0] = 1;
    for (int i = 0; i < K; i ++) {
        for (int j = n - 1; j >= 0; j --) {
            if (vis[j]) {
                if (j + cnt[i] >= n) {
                    if (j + cnt[i] + m <= k) return 0;
                    chkmin(ans, (n - j) * (j + cnt[i] + m - k));
                }
                else vis[j+cnt[i]] = 1;
            }
        }
    }
    for (int i = 0; i < m; i ++) vis[i] = 0;
    vis[0] = 1;
    for (int i = 0; i < K; i ++) {
        for (int j = m - 1; j >= 0; j --) {
            if (vis[j]) {
                if (j + cnt[i] >= m) {
                    if (j + cnt[i] + n <= k) return 0;
                    chkmin(ans, (m - j) * (j + cnt[i] + n - k));
                }
                else vis[j+cnt[i]] = 1;
            }
        }
    }
    return ans;
}

int main() {
    //freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d", &t);
    while (t --) {
        scanf("%d %d %d", &n, &m, &k);
        scanf("%s", s);
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < k; i ++) cnt[s[i]-'A'] ++;
        sort(cnt, cnt + K, greater <int> () );
        printf("%d\n", solve());
    }

    return 0;
}