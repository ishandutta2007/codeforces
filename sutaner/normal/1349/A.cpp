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
#define mo(x) (x = (x >= M) ? (x - M) : x)
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

int n;
int p[maxn], son[maxn], cp = 0;
bool vis[maxn];
void init(){
	srep(i, 2, maxn) {
		if (!vis[i]) p[++cp] = i, son[i] = cp;
		rep(j, 1, cp){
			if (i * p[j] >= maxn) break;
			vis[i * p[j]] = 1;
			son[i * p[j]] = j;
			if (i % p[j] == 0) break;
		}
	}
} 

vector<int> lis[maxn];

int main(){
	int x;
	init();
	scanf("%d", &n);
	ll ans = 1;
	rep(i, 1, n) {
		scanf("%d", &x);
		if (n == 1){
			printf("%d", x);
			return 0;
		}
		while (x > 1){
			int now = son[x];
			ll ct = 1;
			while (son[x] == now){
				ct *= p[now];
				x /= p[now];
			}
			lis[now].pb(ct);
		} 
	} 
	rep(i, 1, cp){
		if (lis[i].empty()) continue;
		sort(lis[i].begin(), lis[i].end());
		int si = lis[i].size();
		if (si <= n - 2) continue;
		else if (si == n - 1) ans *= lis[i][0];
		else ans *= lis[i][1]; 
	}
	printf("%lld", ans);
	return 0;
}