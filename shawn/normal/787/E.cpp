#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int read() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

void write(int x) {
	if (x < 0) {
		putchar('-');
		write(-x);
		return;
	}
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int N = 2e5 + 20; 

struct Segment_tree{
	int ls, rs, sum;
}t[N * 40];
int a[N], vis[N], rt[N];
int n, seg, pos, ans;

void update(int &k, int rt, int l, int r, int x, int w) {
	t[k = ++seg] = t[rt];
	t[k].sum += w;
	if (l == r) return;
	int mid = l + r >> 1;
	if (x <= mid) update(t[k].ls, t[rt].ls, l, mid, x, w);
	else update(t[k].rs, t[rt].rs, mid + 1, r, x, w);
}

int query(int k, int l, int r, int x) {
	if (l == r) return l;
	int mid = l + r >> 1;
	int Sum = t[t[k].ls].sum;
	if (Sum > x) return query(t[k].ls, l, mid, x);
	return query(t[k].rs, mid + 1, r, x - Sum);
}

int main() {
	n = read();
	for (int i = 1; i <= n; i ++) a[i] = read();
	for (int i = n; i; i --) {
		int p = 1;
		if (vis[a[i]]) update(rt[i], rt[i + 1], 1, n + 1, vis[a[i]], -1), p = 0;
		update(rt[i], rt[i + p], 1, n + 1, i, 1);
		vis[a[i]] = i;
	}
	for (int k = 1; k <= n; k ++) {
		for (pos = 1, ans = 0; pos <= n; pos = query(rt[pos], 1, n + 1, k)) 
			ans++;
		write(ans), putchar(32);
	}
	return 0;
}