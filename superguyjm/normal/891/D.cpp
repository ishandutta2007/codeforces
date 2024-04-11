#include <bits/stdc++.h>

#define LL long long
#define pii pair<int,int>
using namespace std;
const int inf = 2147483647;
const int N = 1000001;

int _max(int x, int y) {return x > y ? x : y;}
int _min(int x, int y) {return x < y ? x : y;}
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
void put(LL x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

struct edge {
	int x, y, next;
} e[2 * N]; int len, last[N];
struct DP{
	int a[2][2];
	
	DP() {memset(a, 0, sizeof(a));}
	
	DP trans() {
		DP x;
		x.a[0][0] = a[1][0];
		x.a[0][1] = a[0][0] + a[1][1];
		x.a[1][0] = a[0][0];
		x.a[1][1] = a[0][1];
		return x;
	}
	
	friend DP operator + (DP x, DP y) {
		DP z;
		for(int i = 0; i <= 1; i++) for(int j = 0; j <= 1; j++) {
			for(int k = 0; k <= 1 - i; k++) for(int h = 0; h <= 1 - j; h++){
				z.a[i + k][j + h] += x.a[i][j] * y.a[k][h];
			}
		} return z;
	}
} f[N], g[N], s[N];
queue<int> q;
int tp, sta[N], tot[N], fa[N];

void ins(int x, int y) {
	e[++len].x = x, e[len].y = y;
	e[len].next = last[x], last[x] = len;
}

void dfs(int x) {
	f[x].a[0][0] = 1, tot[x] = 1;
	for(int k = last[x]; k; k = e[k].next) {
		int y = e[k].y;
		if(y != fa[x]) fa[y] = x, dfs(y), f[x] = f[x] + f[y].trans(), tot[x] += tot[y];
	}
}

void bfs() {
	q.push(1);
	s[0].a[0][0] = 1;
	while(!q.empty()) {
		int x = q.front(); q.pop();
		tp = 0; for(int k = last[x]; k; k = e[k].next) if(e[k].y != fa[x]) sta[++tp] = e[k].y, s[tp] = s[tp - 1] + f[sta[tp]].trans();
		DP hh; hh.a[0][0] = 1;
		if(x != 1) hh = g[x].trans();
		for(int i = tp; i >= 1; i--) {
			int y = sta[i];
			g[y] = s[i - 1] + hh;
			hh = hh + f[y].trans();
			q.push(y);
		}
	}
}

int main() {
	int n = read();
	for(int i = 1; i < n; i++) {
		int x = read(), y = read();
		ins(x, y), ins(y, x);
	} dfs(1), 
	bfs();
	LL ans = 0;
	for(int i = 2; i <= n; i++) {
		if(f[i].a[1][0] == 1 && g[i].a[1][0] == 1) ans += (LL)tot[i] * (n - tot[i]);
		ans += (LL)(f[i].a[0][0] + f[i].a[1][1]) * (g[i].a[0][0] + g[i].a[1][1]);
	} put(ans), puts("");
	return 0;
}