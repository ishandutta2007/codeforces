#include <bits/stdc++.h>

#define LL long long
#define pii pair<int,int>
using namespace std;
const int inf = 2147483647;
const int M = 225, N = 1e5 + 1;

int _max(int x, int y) {return x > y ? x : y;}
int _min(int x, int y) {return x < y ? x : y;}
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return x * f;
}
void put(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) put(x / 10);
	putchar(x % 10 + '0');
}

bool v[M];
int mx[M], lzy[M], hd[M][N];
int a[N], fa[N], tot[N], BL[N], ll[M], rr[M];

int findfa(int x) {
	if(fa[x] ^ x) fa[x] = findfa(fa[x]);
	return fa[x];
}

void cmx(int bb) {
	while(!hd[bb][mx[bb]]) mx[bb]--;
}

void change(int bb) {
	for(int i = ll[bb]; i <= rr[bb]; i++) a[i] = a[findfa(i)], hd[bb][a[i]] = 0;
	for(int i = ll[bb]; i <= rr[bb]; i++) fa[i] = i, tot[i] = 1;
	for(int i = ll[bb]; i <= rr[bb]; i++) {
		if(!hd[bb][a[i]]) hd[bb][a[i]] = i;
		else tot[hd[bb][a[i]]] += tot[i], fa[i] = hd[bb][a[i]];
	} cmx(bb);
}

void san(int bb, int l, int r, int x) {
	for(int i = ll[bb]; i <= rr[bb]; i++) a[i] = a[findfa(i)], hd[bb][a[i]] = 0;
	for(int i = l; i <= r; i++) if(a[i] - lzy[bb] > x) a[i] -= x;
	for(int i = ll[bb]; i <= rr[bb]; i++) fa[i] = i;
	change(bb);
}

int main() {
	int n = read(), m = read(), kk = sqrt(2 * n);
	for(int i = 1; i <= n; i++) {
		BL[i] = (i - 1) / kk + 1, fa[i] = i;
		if(BL[i] != BL[i - 1]) ll[BL[i]] = i, rr[BL[i - 1]] = i - 1;
	} ll[1] = 1, rr[BL[n]] = n;
	for(int i = 1; i <= n; i++) a[i] = read(), mx[BL[i]] = _max(mx[BL[i]], a[i]);
	for(int i = 1; i <= BL[n]; i++) change(i);
	while(m--) {
		int o = read(), l = read(), r = read(), x = read();
		int bl = BL[l], br = BL[r];
		if(o == 1) {
			if(bl == br) {san(bl, l, r, x); continue;}
			san(bl, l, rr[bl], x), 
			san(br, ll[br], r, x);
			for(int i = bl + 1; i < br; i++) {
				if(x * 2 > mx[i] - lzy[i]) {
					for(int j = x + 1 + lzy[i]; j <= mx[i]; j++) if(hd[i][j]){
						if(!hd[i][j - x]) hd[i][j - x] = hd[i][j], a[hd[i][j]] = j - x;
						else tot[hd[i][j - x]] += tot[hd[i][j]], fa[hd[i][j]] = hd[i][j - x];
						hd[i][j] = 0;
					} cmx(i);
				} else {
					for(int j = lzy[i] + 1; j <= lzy[i] + x; j++) if(hd[i][j]){
						if(!hd[i][j + x]) hd[i][j + x] = hd[i][j], a[hd[i][j]] = j + x;
						else tot[hd[i][j + x]] += tot[hd[i][j]], fa[hd[i][j]] = hd[i][j + x];
						hd[i][j] = 0;
					} lzy[i] += x;
				}
			}
		} else {
			int ans = 0;
			if(bl == br) {
				change(bl);
				for(int i = l; i <= r; i++) if(a[i] - lzy[bl] == x) ans++;
				put(ans), puts(""); continue;
			} change(bl), change(br);
			for(int i = l; i <= rr[bl]; i++) if(a[i] - lzy[bl] == x) ans++;
			for(int i = ll[br]; i <= r; i++) if(a[i] - lzy[br] == x) ans++;
			for(int i = bl + 1; i < br; i++) if(x + lzy[i] < N){
				if(hd[i][x + lzy[i]]) ans += tot[hd[i][x + lzy[i]]];
			} put(ans), puts("");
		}
	}
	return 0;
}