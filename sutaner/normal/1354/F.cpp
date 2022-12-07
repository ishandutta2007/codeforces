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
#define maxn 85
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

const int inf = 2000000000;

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

int n, k, ti;
struct ele{
	int b, a, id;
	ele(int b, int a, int id) : b(b), a(a), id(id){}
	ele(){}
	bool operator < (const ele y) const{
		return b < y.b;
	}
}p[maxn];

int vis[maxn][maxn];
int dp[maxn][maxn];
int DP(int pos, int rest){
	if (pos > n) {
		if (rest == 0) return 0;
		else return -inf;
	}
	if (vis[pos][rest] == ti) return dp[pos][rest];
	vis[pos][rest] = ti;
	int& ans = dp[pos][rest];
	if (rest) return ans = max(DP(pos + 1, rest - 1) + p[pos].a + p[pos].b * (k - rest), DP(pos + 1, rest) + p[pos].b * (k - 1));
	else return ans = DP(pos + 1, rest) + p[pos].b * (k - 1);
}

int ans[maxn];
void find_ans(int pos, int rest){	
	if (pos > n) return;
	if (rest){
		int A = DP(pos + 1, rest - 1) + p[pos].a + p[pos].b * (k - rest);
		int B = DP(pos + 1, rest) + p[pos].b * (k - 1);
		if (A > B) find_ans(pos + 1, rest - 1), ans[pos] = p[pos].id;
		else find_ans(pos + 1, rest), ans[pos] = -p[pos].id;
	}
	else {
		find_ans(pos + 1, rest);
		ans[pos] = -p[pos].id;
	}
}

int main(){
	int T, x, y;
	scanf("%d", &T);
	while (T--){	
		ti++;
		scanf("%d%d", &n, &k);
		rep(i, 1, n) scanf("%d%d", &x, &y), p[i] = ele(y, x, i);
		sort(p + 1, p + 1 + n);
		//printf("%d\n", DP(1, k));
		//cerr << DP(1, k) << endl;
		DP(1, k), find_ans(1, k);
		
		int num = n;
		rep(i, 1, n) if (ans[i] < 0) num++;
		printf("%d\n", num);
		rep(i, 1, n){
			if (k > 1 && ans[i] > 0) printf("%d ", ans[i]), k--;
		}
		rep(i, 1, n){
			if (ans[i] < 0) printf("%d %d ", -ans[i], ans[i]);
		}
		per(i, n, 1){
			if (ans[i] > 0){
				printf("%d\n", ans[i]); break;
			}
		} 
	} 
	
	return 0;
}