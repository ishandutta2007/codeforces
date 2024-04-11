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

int ufs[30], siz[30];
int find_root(int x){
	return ufs[x] = (ufs[x] == x) ? x : find_root(ufs[x]);
}
int n; char s[maxn], t[maxn];
//bool hav[30][30];
//int a[30];

void merge(int x, int y){
	x = find_root(x), y = find_root(y);
	if (!siz[x]) siz[x] = 1;
	if (!siz[y]) siz[y] = 1;
	if (x == y) return;
	ufs[x] = y;
	siz[y] += siz[x];
}

int main(){
	int T; scanf("%d", &T);
	while (T--){
		//int res = 0, mx = 0;
		int res = 0;
		scanf("%d", &n);
		scanf("%s%s", s + 1, t + 1);
		rep(i, 1, 20) ufs[i] = i, siz[i] = 0;
		rep(i, 1, n){
			if (s[i] > t[i]) {
				printf("-1\n");
				goto done;
			}
			else if (s[i] < t[i]){
				merge(s[i] - 'a' + 1, t[i] - 'a' + 1);
				//hav[s[i] - 'a'][t[i] - 'a'] = 1;
			}
		}  
		rep(i, 1, 20) {
			if (ufs[i] == i && siz[i]) res += siz[i] - 1;
		}
		printf("%d\n", res);
		done:;
		/*
		rep(i, 0, 19) rep(j, 0, 19) {
			if (hav[i][j]) {
				rep(k, i + 1, j) a[k]++;
			}
		} 
		rep(i, 1, 19) {
			while (i <= 19 && !a[i]) i++;
			while (i <= 19 && a[i]) mx = max(mx, a[i]), i++;
			i--;
			res += mx, mx = 0;
		}
		printf("%d\n", res);
		done:rep(i, 0, 19) rep(j, 0, 19) hav[i][j] = 0; 
		rep(i, 1, 19) a[i] = 0;
		*/
	} 
	return 0;
}