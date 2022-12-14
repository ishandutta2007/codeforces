#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

void wt(int x) {
	if (x >= 10) wt(x / 10);
	putchar(x % 10 + 48);
}

const int inf = 1e9 + 1;
const int N = 300035;

int v[N<<2], tag[N<<2], cnt;
int h[N], n, m, op[N], x[N], y[N], w[N];
map <int, int> vis;

void upd(int k, int w) {
	if (!v[k]) tag[k] = min(tag[k], w);
}

void down(int k) {
	upd(k << 1, tag[k]);
	upd(k << 1 | 1, tag[k]);
	tag[k] = inf;
}

void up(int k) {
	tag[k] = max(tag[k << 1], tag[k << 1 | 1]);
}

void modify(int k, int l, int r, int x, int y, int w, int op) {
	if (x == l && r == y) {
		if (op == 1) upd(k, w);
		else if (op == 2) v[k] = 1;
		else tag[k] = w;
		return;
	}
	if (op < 3) down(k);
	int mid = l + r >> 1;
	if (y <= mid) modify(k << 1, l, mid, x, y, w, op);
	else if (x > mid) modify(k << 1 | 1, mid + 1, r, x, y, w, op);
	else modify(k << 1, l, mid, x, mid, w, op), modify(k << 1 | 1, mid + 1, r, mid + 1, y, w, op);
	if (op == 3) up(k);
}

int query(int k, int l, int r, int x, int y) { 
	if (x == l && r == y) return tag[k];
	int mid = l + r >> 1;
	if (y <= mid) return query(k << 1, l, mid, x, y);
	else if (x > mid) return query(k << 1 | 1, mid + 1, r, x, y);
	else return max(query(k << 1, l, mid, x, mid), query(k << 1 | 1, mid + 1, r, mid + 1, y));	
}

void tour(int k, int l, int r) {
	if (l == r) {
		h[l] = tag[k];
		return;
	}
	down(k);
	int mid = l + r >> 1;
	tour(k << 1, l, mid);
	tour(k << 1 | 1, mid + 1, r);
	up(k);
}
 
int main() {
	n = rd(), m = rd();
	for (int i = 1; i <= m; i ++) {
		op[i] = rd();
		if (op[i] == 1) x[i] = rd(), y[i] = rd(), w[i] = rd();
		else x[i] = y[i] = rd(), w[i] = rd();
	}
	for (int i = 1; i <= (n << 2); i ++) tag[i] = inf;
	for (int i = 1; i <= m; i ++) 
		modify(1, 1, n, x[i], y[i], w[i], op[i]);
	tour(1, 1, n);
	for (int i = 1; i <= m; i ++) {
		if (op[i] == 2) modify(1, 1, n, x[i], y[i], w[i], 3);
		else if (query(1, 1, n, x[i], y[i]) != w[i]) return puts("NO"), 0; 
	}
	puts("YES");
	for (int i = 1; i <= n; i ++) if (h[i] == inf) cnt++;
	if (cnt > 1) {
		for (int i = 1; i <= n; i ++) 
			if (h[i] == inf) {
				if (cnt > 1) h[i] = (1 << 29) - 1, cnt = 1;
				else if (cnt) h[i] = inf - 1, cnt = 0;
				else h[i] = 0;
			}
	}
	else {
		cnt = 0; int j; 
		for (int i = 1; i <= n; i ++) {
			if (h[i] != inf) {
				if (!vis[h[i]]) vis[h[i]] = 1;
				else {
					for (j = 29; j >= 0 && (1 << j) - 1 > h[i]; j --);
					h[i] = (1 << j) - 1;
				}
				cnt |= h[i]; 
			}
		}
		for (int i = 1; i <= n; i ++) {
			if (h[i] == inf) {
				h[i] = 0;
				for (j = 29; j >= 0; j --) 
				if ((~cnt >> j & 1) && h[i] + (1 << j) < inf) h[i] |= 1 << j;
			}
		}
	}
	for (int i = 1; i <= n; i ++) wt(h[i]), putchar(32);
	return 0;
}