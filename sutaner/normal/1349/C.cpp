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
#define maxn 1020
#define maxm
#define maxq 100020
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

int n, m, q;
struct query{
	int x, y, id;
	ll t;
	query(int x, int y, ll t, int id) : x(x), y(y), t(t), id(id){}
	query(){}
	bool operator < (const query b) const{
		return t < b.t;
	}
}lis[maxq];
int ans[maxq];
char g[maxn][maxn];
int tt[maxn][maxn]; 
bool vis[maxn][maxn];
bool ok[maxn][maxn];
pii bfs[maxn * maxn];
int head = 0, tail = 0;

void debug(int t){
	rep(i, 1, n){
		rep(j, 1, m){
			if (ok[i][j]) printf("%d", (g[i][j] - '0') ^ ((t - tt[i][j]) & 1));
			else printf("%d", g[i][j] - '0');
		}
		printf("\n");
	}
	printf("\n");
}
int main(){
	int x, y;
	ll z;
	scanf("%d%d%d", &n, &m, &q);
	rep(i, 1, n) scanf("%s", g[i] + 1);
	rep(i, 1, q){
		scanf("%d%d%lld", &x, &y, &z);
		lis[i] = query(x, y, z, i);
	}
	sort(lis + 1, lis + 1 + q);
	
	rep(i, 1, n){
		rep(j, 1, m){
			bool& okk = ok[i][j];
			if (i - 1 >= 1 && g[i - 1][j] == g[i][j]) okk = 1;
			if (i + 1 <= n && g[i + 1][j] == g[i][j]) okk = 1;
			if (j - 1 >= 1 && g[i][j - 1] == g[i][j]) okk = 1;
			if (j + 1 <= m && g[i][j + 1] == g[i][j]) okk = 1;
			vis[i][j] = ok[i][j];
		}
	}
	rep(i, 1, n){
		rep(j, 1, m){
			if (ok[i][j]){
				if (i - 1 >= 1 && !ok[i - 1][j] && !vis[i - 1][j]) bfs[++head] = pii(i - 1, j), vis[i - 1][j] = 1;
				if (i + 1 <= n && !ok[i + 1][j] && !vis[i + 1][j]) bfs[++head] = pii(i + 1, j), vis[i + 1][j] = 1;
				if (j - 1 >= 1 && !ok[i][j - 1] && !vis[i][j - 1]) bfs[++head] = pii(i, j - 1), vis[i][j - 1] = 1;
				if (j + 1 <= m && !ok[i][j + 1] && !vis[i][j + 1]) bfs[++head] = pii(i, j + 1), vis[i][j + 1] = 1;
			}
		}
	}
	if (!head){
		bool okk = ok[1][1];
		if (okk){
			rep(i, 1, q){
				query op = lis[i];
				ans[op.id] = g[op.x][op.y] - '0';
				ans[op.id] ^= (op.t & 1);
			}
		}
		else {
			rep(i, 1, q){
				query op = lis[i];
				ans[op.id] = g[op.x][op.y] - '0';
			}
		}
	}
	else {
		int t = 0, ptr = 1, last = 1;
		while (last <= head){
			t++;
			int _head = head;
			rep(k, last, _head){
				pii op = bfs[k]; 
				ok[op.fi][op.se] = 1;
				tt[op.fi][op.se] = t;
				//if (rev) g[op.fi][op.se] = '0' + '1' - g[op.fi][op.se];
			}
			rep(k, last, _head){
				pii op = bfs[k]; 
				int i = op.fi, j = op.se;
				if (i - 1 >= 1 && !ok[i - 1][j] && !vis[i - 1][j]) bfs[++head] = pii(i - 1, j), vis[i - 1][j] = 1;
				if (i + 1 <= n && !ok[i + 1][j] && !vis[i + 1][j]) bfs[++head] = pii(i + 1, j), vis[i + 1][j] = 1;
				if (j - 1 >= 1 && !ok[i][j - 1] && !vis[i][j - 1]) bfs[++head] = pii(i, j - 1), vis[i][j - 1] = 1;
				if (j + 1 <= m && !ok[i][j + 1] && !vis[i][j + 1]) bfs[++head] = pii(i, j + 1), vis[i][j + 1] = 1;
			}
			last = _head + 1;
			
			//debug(t);
			
			while (ptr <= q && lis[ptr].t == t){
				query op = lis[ptr];
				ans[op.id] = g[op.x][op.y] - '0';
				if (ok[op.x][op.y]) ans[op.id] ^= ((t - tt[op.x][op.y]) & 1);  
				ptr++;
			}
		}
		//rep(i, t + 1, 10) debug(i);
		rep(i, ptr, q){
			query op = lis[i];
			ans[op.id] = g[op.x][op.y] - '0';
			if (ok[op.x][op.y]) ans[op.id] ^= ((op.t - tt[op.x][op.y]) & 1); 
		}
	}
	rep(i, 1, q) printf("%d\n", ans[i]); 
	return 0;
}