#include <bits/stdc++.h>

#define LL long long
#define pii pair<int,int>
using namespace std;
const int inf = 2147483647;
const int N = 2001;

int _max(int x, int y) {return x > y ? x : y;}
int _min(int x, int y) {return x < y ? x : y;}
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
inline char rd() {
    char ch = getchar();
    while(ch < 'X' || ch > 'Z') ch = getchar();
    return ch;
}
void put(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

struct edge {
	int x, y, next;
} e[2 * N]; int len, last[N];
int n, id, zz, ll[N], rr[N], tot[N], s[N];
int root, f[N], son[N][2];
bool v[N], gg[N][N];
int qq, u[N], V[N];

int Son(int x) {return son[f[x]][1] == x;}

void ins(int x, int y) {
	e[++len].x = x, e[len].y = y;
	e[len].next = last[x], last[x] = len;
	e[++len].x = y, e[len].y = x;
	e[len].next = last[y], last[y] = len;
}

int findrt(int x, int fa) {
	tot[x] = (x >= n), s[x] = 0;
	if(x >= n) return -1;
	int hh = -1;
	for(int k = last[x]; k; k = e[k].next) {
		int y = e[k].y;
		if(y != fa && !v[y]) {
			int g = findrt(y, x);
			if(hh == -1) hh = g;
			else if(g != -1 && s[g] < s[hh]) hh = g;
			s[x] = _max(s[x], tot[y]);
			tot[x] += tot[y];
		}
	} s[x] = _max(s[x], zz - tot[x]);
	if(hh == -1) hh = x;
	else if(s[x] < s[hh]) hh = x;
	return hh;
}

int gettot(int x, int fa) {
	if(x >= n) return 1;
	int sum = 0;
	for(int k = last[x]; k; k = e[k].next) {
		int y = e[k].y;
		if(y != fa && !v[y]) sum += gettot(y, x);
	} return sum;
}

void solve(int z, int now) {
	int x = findrt(z, 0);
	v[x] = 1;
	printf("%d %d %d\n", ll[x] - n + 1, rr[x] - n + 1, now);
	fflush(stdout);
	char c = rd();
	if(c == 'X') {
		if(!f[x]) root = ++id, u[++qq] = id, V[qq] = x, u[++qq] = id, V[qq] = now + n - 1, son[id][0] = x, ll[id] = ll[x], son[id][1] = rr[id] = now + n - 1, f[x] = id;
		else if(v[f[x]]) {
			++id; gg[x][f[x]] = gg[f[x]][x] = 1;
			u[++qq] = id, V[qq] = x;
			u[++qq] = id, V[qq] = f[x];
			u[++qq] = id, V[qq] = now + n - 1;
			f[id] = f[x], son[f[x]][Son(x)] = id, f[x] = id;
			son[id][0] = x, son[id][1] = now + n - 1;
			ll[id] = ll[x], rr[id] = now + n - 1;
		} else zz = gettot(f[x], 0), solve(f[x], now);
	} else {
		int o = c == 'Y';
		if(son[x][o] >= n || v[son[x][o]]) {
			++id, gg[x][son[x][o]] = gg[son[x][o]][x] = 1;
			u[++qq] = id, V[qq] = x;
			u[++qq] = id, V[qq] = son[x][o];
			u[++qq] = id, V[qq] = now + n - 1;
			son[id][o] = son[x][o], son[id][o ^ 1] = now + n - 1;
			if(o) rr[id] = son[x][o] >= n ? son[x][o] : ll[son[x][o]], ll[id] = now + n - 1;
			else ll[id] = son[x][o] >= n ? son[x][o] : ll[son[x][o]], rr[id] = now + n - 1;
			if(son[x][o] < n) f[son[x][o]] = id; son[x][o] = id, f[id] = x;
		} else zz = gettot(son[x][o], 0), solve(son[x][o], now);
	}
}

int main() {
	n = read();
	int x = 1, y = 2, z = 3;
	printf("%d %d %d\n", x, y, z);
	fflush(stdout);
	char c = rd(); id = 2;
	if(c == 'X');
	if(c == 'Y') swap(x, y), swap(y, z);
	if(c == 'Z') swap(y, z);
	ll[2] = son[2][0] = x + n - 1, son[2][1] = ll[1] = rr[2] = y + n - 1, son[1][0] = 2, son[1][1] = rr[1] = z + n - 1, f[2] = 1;
	ins(2, x + n - 1), ins(2, y + n - 1), ins(1, 2), ins(1, z + n - 1);
	root = 1;
	for(int i = 4; i <= n; i++) {
		memset(v, 0, sizeof(v));
		zz = i - 1;
		qq = 0, solve(root, i);
		int kk = len;
		len = 0; memset(last, 0, sizeof(last));
		for(int i = 1; i <= kk; i += 2) {
			if(gg[e[i].x][e[i].y]) {gg[e[i].x][e[i].y] = gg[e[i].y][e[i].x] = 0; continue;}
			ins(e[i].x, e[i].y);
		} for(int j = 1; j <= qq; j++) ins(u[j], V[j]);
	} for(int i = 1; i < n; i++) f[son[i][0]] = i, f[son[i][1]] = i;
	puts("-1");
	for(int i = 1; i < 2 * n; i++) put(f[i] == 0 ? -1 : f[i]), putchar(' ');
	puts("");
	fflush(stdout);
	return 0;
}