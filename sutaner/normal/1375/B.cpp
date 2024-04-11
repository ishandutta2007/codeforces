#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 310
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n, m, a[maxn][maxn], b[maxn][maxn];
inline bool judge(int i, int j){
	return 1 <= i && i <= n && 1 <= j && j <= m;
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		rep(i, 1, n) rep(j, 1, m) scanf("%d", &a[i][j]), b[i][j] = 0;
		rep(i, 1, n){
			rep(j, 1, m){
				for (register int k = -1; k <= 1; k += 2){
					if (judge(i + k, j)) b[i][j]++;
					if (judge(i, j + k)) b[i][j]++;
				}
			}
		}
		rep(i, 1, n) rep(j, 1, m) {
			if (a[i][j] > b[i][j]) {printf("NO\n"); goto fail;}
		}
		printf("YES\n");
		rep(i, 1, n) {rep(j, 1, m) printf("%d ", b[i][j]); printf("\n");}
		fail:;
	}
	return 0;
}