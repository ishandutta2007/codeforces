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
#define maxn 400020
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
char s[maxn];
int n;

int main(){
	int T; scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		scanf("%s", s + 1);
		int res = 0; 
		int first = -1, second = -1, last = -1;
		rep(i, 1, n) {
			char now = s[i];
			int _i = i;
			while (i <= n && s[i] == now) i++;
			int len = i - _i;
			i--;
			if (first == -1) first = len; 
			else {
				if (last != -1) res += last / 3;
				last = len;
			} 
		}
		second = last;
		if (first == n) {
			printf("%d\n", (n - 1) / 3 + 1);
		}
		else {
			if (s[1] == s[n]) res += (first + second) / 3;
			else res += first / 3 + second / 3;
			printf("%d\n", res);
		}
	} 
	return 0;
}