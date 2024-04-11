#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define x first
#define y second
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
template <class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template <class T> void chkmin(T &a, T b) {if (a > b) a = b;}

typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int inf = 0x3f3f3f3f;

#define N 10005
#define M 20005

int n, m, tot, to[M], nxt[M], head[N];
bool vis[N];
int dp[N], a[N], b[M], g, ans;

void add_edge(int x, int y) {
    tot ++;
    to[tot] = y; nxt[tot] = head[x]; head[x] = tot;
    return;
}

void dfs(int k, int p = 0) {
    dp[k] = dp[p] + 1; vis[k] = 1;
    for (int i = head[k]; i; i = nxt[i]) {
		int y = to[i];
		if (y == p || dp[y] > dp[k]) continue;
        if (!vis[y]) {
            dfs(y, k);
            a[k] += a[y], b[i] = a[y];
        }
        else if (dp[k] + dp[y] & 1) a[y] ++, a[k] --;
		else a[y] --, a[k] ++, b[i] = 1, g ++;
	}
}

int main() {
    scanf("%d %d", &n, &m);
    int x, y;
    f1(i, 1, m) {
        scanf("%d %d", &x, &y);
        add_edge(x, y);
        add_edge(y, x);
    }
    f1(i, 1, n) if (!vis[i]) dfs(i);
    if (!g) {
        printf("%d\n", m);
        f1(i, 1, m) printf("%d ", i);
        return 0;
    }
    f1(i, 1, tot) if (b[i] == g) ans ++;
    printf("%d\n", ans);
    f1(i, 1, tot) if (b[i] == g) printf("%d ", i + 1 >> 1);
	return 0;
}