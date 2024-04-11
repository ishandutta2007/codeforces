#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f1(i, a, b) for (int i = a; i <= b; i ++)

const int inf = 0x3f3f3f3f;

#define N 1000005
#define P 30
#define M 20000005

int n, k, tot, root;
int ak[30];
int son[M][2], g[M];
ll ans;

void calc(int v, int *a) {
    memset(a, 0, 120);
    int i = 0;
    while (v) {
        a[i ++] = v & 1;
        v >>= 1;
    }
    return;
}

int make_node() {
    ++ tot;
    return tot;
}

int get_ans(int x, int d) {
	if (!son[x][d]) return 0;
	return g[son[x][d]];
}

int ax[P];
void update(int x) {
    int nd = root;
    g[root] ++;
    for (int i = P - 1; i >= 0; i --) {
		if (!son[nd][ax[i]]) son[nd][ax[i]] = make_node();
		nd = son[nd][ax[i]];
		g[nd] ++;
    }
    return;
}

void query(int x) {
    int nd = root;
    for (int i = P - 1; i >= 0; i --) {
        if (!ak[i]) {
			ans += get_ans(nd, ax[i] ^ 1);
			nd = son[nd][ax[i]];
        }
        else nd = son[nd][ax[i]^1];
        if (!nd) return;
    }
    ans += g[nd];
    return;
}

int main() {
	int x, y = 0;
    scanf("%d %d", &n, &k);
    root = make_node();
    update(0);
    calc(k, ak);
    f1(i, 1, n) {
        scanf("%d", &x);
        y ^= x;
		calc(y, ax);
        query(y);
        update(y);
    }
    printf("%I64d\n", ans);
	return 0;
}