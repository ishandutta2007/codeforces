#include <cstdio>
#include <algorithm>

using namespace std;

int rd() {
	int x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 3e5 + 10;

struct edge {
	int nxt, to;
}e[N << 1];
int head[N], a[N], n, mx, c1, c2, cnt, pos, ans;
bool flag;

void insert(int u, int v) {
	e[++cnt].nxt = head[u], e[head[u] = cnt].to = v;
}

bool chk1(int u) {
	int t = 0;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (a[v] == mx - 1) t ++;
	}
	return t == c2;
}


bool chk2(int u) {
	int t = a[u] == mx;
	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if (a[v] == mx) t ++;
	}
	return t == c1;
}

int main() {
	n = rd();
	mx = -0x7f7f7f7f;
	for (int i = 1; i <= n; i ++) a[i] = rd(), mx = max(a[i], mx);
	for (int i = 1; i <= n; i ++) c1 += (a[i] == mx) ? 1 : 0, pos = a[i] == mx ? i : pos;
	for (int i = 1; i <= n; i ++) c2 += (a[i] == (mx - 1)) ? 1 : 0;
	for (int i = 1; i < n; i ++) {
		int u = rd(), v = rd();
		insert(u, v), insert(v, u); 
	}
	if (c1 == 1 && chk1(pos)) ans = mx;
	else {
		for (int i = 1; i <= n; i ++) if (chk2(i)) {
			flag = 1;
			break;
		}
		if (flag) ans = mx + 1;
		else ans = mx + 2;	
	}
	printf("%d", ans);
	return 0;	
}