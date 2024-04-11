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
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define maxr 2000020
#define maxn 2000020
#define maxm
#define maxs
#define maxb
#define M 1000000007
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

int n, p, a[maxn];

vector<pii> type[maxn];

int power(int x, int y){
	ll ans = 1, con = x;
	while (y){
		if (y & 1) ans = ans * con % M;
		con = con * con % M;
		y >>= 1;
	}
	return ans;
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &p);
		rep(i, 1, n) scanf("%d", a + i);
		if (p == 1){
			if (n & 1) printf("1\n");
			else printf("0\n");
			continue;
		}
		sort(a + 1, a + 1 + n); 
		ll ans = 0;
		per(i, n, 1){
			int now = a[i], _i = i;
			while (i >= 1 && a[i] == now) i--;
			int ct = _i - i; 
			if (ct & 1){
				ans += power(p, now);
				mo(ans);
				ll rest = 1; 
				int nst = now;
				while (i >= 1 && rest){
					int now = a[i], _i = i;
					while (nst > now && rest <= n) rest = rest * p, nst--; 
					while (rest && i >= 1 && now == a[i]){
						ans = ans + M - power(p, now);
						mo(ans);
						i--;
						rest--;
					}
				}
			}
			i++;
		}
		printf("%lld\n", ans);
	} 
	return 0;
}