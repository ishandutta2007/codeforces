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
#define maxn
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

int num[31];
void dep(int x){
	int now = 0;
	while (x){
		if (x & 1) num[now]++;
		x >>= 1, now++;
	}
}

int main(){
	int T, x, n; scanf("%d", &T);
	while (T--){
		rep(i, 0, 30) num[i] = 0;
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &x), dep(x);
		int f = -1;
		per(i, 30, 0) if (num[i] & 1) {f = i; break;} 
		if (f == -1) {
			printf("DRAW\n"); goto done;
		}
		else {
			int num1 = num[f], num0 = n - num1;
			int win = 0;
			if ((num1 >> 1) & 1) win = 0;
			else win = 1;
			if (!win) win ^= (num0 & 1);
			if (win) printf("WIN\n");
			else printf("LOSE\n");
		}
		done:;
	} 
	return 0;
}