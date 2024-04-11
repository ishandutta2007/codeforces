#include <bits/stdc++.h>
using namespace std;
#define N 55
#define M 105

int a[5], b[5], R, sum;
const int mod = 1e9 + 7;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int expmod(int a, int b, int mod) {
    int res = 1;
    for ( ; b; b >>= 1) {
        if (b & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
    }
    return res;
}


int C;

struct Node {
    vector <int> v;
    Node operator * (int a) {
        Node res;
        res.v.resize(C);
        for (int i = 0; i < C; i ++) res.v[i] = 1ll * v[i] * a % mod;
        return res;
    }
    Node operator - (const Node &a) const {
        Node res;
        res.v.resize(C);
        for (int i = 0; i < C; i ++) res.v[i] = (v[i] - a.v[i] + mod) % mod;
        return res;
    }
} nd[M * M];

bool vis[M], ris[M * M], wis[M];
int x[M];

int idx(int x, int y) {
	return (x + R + 1) * C + y + R;
}

int d[M][M], c[M], e[M], ds;

void func(int k) {
    ++ ds;
    for (int i = 1; i < C; i ++) d[ds][i] = nd[k].v[i-1];
    c[ds] = (mod - nd[k].v[C-1]) % mod;
    return;
}

void pulja() {
    int now = 1;
    for (int j = 1; j < C; j ++) {
        bool flag = 0;
        for (int i = now; i < C; i ++) if (d[i][j]) {
            for (int ii = 1; ii < C; ii ++) swap(d[i][ii], d[now][ii]);
            swap(c[now], c[i]);
            flag = 1;
            break;
        }
		if (!flag) continue;
        int inv = expmod(d[now][j], mod - 2, mod);
        for (int i = j; i < C; i ++) d[now][i] = 1ll * d[now][i] * inv % mod; c[now] = 1ll * c[now] * inv % mod;
        for (int i = 1; i < C; i ++) if (d[i][j]) {
            if (i == now) continue;
            int co = d[i][j];
            for (int ii = j; ii < C; ii ++) d[i][ii] = ((d[i][ii] - 1ll * co * d[now][ii]) % mod + mod) % mod;
            c[i] = ((c[i] - 1ll * co * c[now]) % mod + mod) % mod;
        }
        e[now ++] = j;
    }
    for (int i = 1; i < now; i ++) x[e[i]] = c[i];
}

int main() {
	scanf("%d", &R);
    for (int i = 0; i < 4; i ++) scanf("%d", &a[i]), sum += a[i];
    int si = expmod(sum, mod - 2, mod);
    for (int i = 0; i < 4; i ++) a[i] = 1ll * a[i] * si % mod, b[i] = expmod(a[i], mod - 2, mod);
    C = 2 * R + 2;
    for (int i = 0; i < M * M; i ++) nd[i].v.resize(C, 0);
    for (int i = R + 1; i >= 0; i --) {
        for (int j = -R; j <= R; j ++) {
            if (vis[j+R]) continue;
            if (j * j + i * i <= R * R) {
				vis[j+R] = 1;
                int k = idx(i, j);
                ris[k] = 1;
                nd[k].v[j+R] = 1;
				continue;
            }
        }
    }
    int y = idx(0, 0);
    memset(vis, 0, sizeof vis);
    for (int i = R; i >= - R - 1; i --) {
		for (int j = -R; j <= R; j ++) {
            if (i * i + j * j > R * R) {
				if (vis[j+R]) continue;
                if (!wis[j+R]) continue;
            }
            int k = idx(i, j);
			if (ris[k]) {
                wis[j+R] = 1;
				continue;
			}
            int kk = idx(i + 1, j);
            nd[k] = nd[kk];
            nd[k].v[C-1] = (nd[k].v[C-1] + mod - 1) % mod;
			for (int t = 0; t < 4; t ++) {
                if (t == 2) continue;
                int x = i + 1 + dx[t], y = j + dy[t];
				if (x * x + y * y > R * R) continue;
                nd[k] = nd[k] - nd[idx(x, y)] * a[t];
			}
            nd[k] = nd[k] * b[2];
            if (i * i + j * j > R * R) {
				func(k);
				vis[j+R] = 1;
            }
		}
    }
    pulja();
    int k = idx(0, 0);
    int ans = 0;
    for (int i = 1; i < C; i ++) ans = (ans + 1ll * nd[k].v[i-1] * x[i]) % mod;
    ans = (ans + nd[k].v[C-1]) % mod;
    printf("%d\n", ans);
}