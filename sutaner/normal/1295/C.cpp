#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 200020
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

int nex[maxn][26];
int now[26];
char s[maxn], t[maxn];

int main(){
	
		//freopen(".in", "r", stdin);
		
	ios :: sync_with_stdio(false), cin.tie(0);
	int T;
	scanf("%d", &T);
	while (T--){	
		scanf("%s%s", s + 1, t + 1);
		int n = strlen(s + 1), m = strlen(t + 1);
		rep(i, 0, 25) now[i] = -1;
		per(i, n, 0){
			rep(j, 0, 25) nex[i][j] = now[j];
			now[s[i] - 'a'] = i;
		} 
		int str = 0, ans = 0;
		rep(i, 1, m){
			bool f = 0; str = 0;
			while (nex[str][t[i] - 'a'] != -1) f = 1, str = nex[str][t[i] - 'a'], i++; i--;
			if (f) ans++;
			else {ans = -1; goto jump;}
		}
		jump: printf("%d\n", ans);
	}
	return 0;
}