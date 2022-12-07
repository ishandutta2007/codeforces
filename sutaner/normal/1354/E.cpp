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
#define maxn 6020
#define maxm 200020
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

int n, m, n1, n2, n3;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}

int ct = 0;
int c1[maxn], c2[maxn];
vector<int> lis[maxn];
int c[maxn];
bool dfs(int x, int cc){
	lis[ct].pb(x);
	c[x] = cc;
	if (cc == 1) c1[ct]++;
	else c2[ct]++;
	erep(i, x){
		int op = e[i].to;
		if (c[op]) {
			if (c[op] != 3 - cc) return false;
			continue;
		}
		if (!dfs(op, 3 - cc)) return false;
	}
	return true;
}

bool vis[maxn][maxn];
bool dp[maxn][maxn];
bool DP(int pos, int rest){
	if (rest < 0) return false;
	if (pos > ct){
		if (rest) return false;
		else return true;
	}
	if (vis[pos][rest]) return dp[pos][rest];
	vis[pos][rest] = 1;
	bool& ans = dp[pos][rest];
	return ans = DP(pos + 1, rest - c1[pos]) || DP(pos + 1, rest - c2[pos]);
}

int anslis[maxn];
int cs = 0;
void find_ans(int pos, int rest){	
	if (pos > ct) return; 
	if (DP(pos + 1, rest - c1[pos])) anslis[++cs] = 1, find_ans(pos + 1, rest - c1[pos]);
	else anslis[++cs] = 2, find_ans(pos + 1, rest - c2[pos]);
}
int out[maxn];
int main(){
	scanf("%d%d", &n, &m);
	scanf("%d%d%d", &n1, &n2, &n3);
	int x, y;
	rep(i, 1, m) scanf("%d%d", &x, &y), Add_Edge(x, y);
	rep(i, 1, n) {	
		if (!c[i]) {
			++ct;
			if (!dfs(i, 1)){
				printf("NO\n");
				return 0;
			}
		}
	}
	if (!DP(1, n2)) {
		printf("NO\n");
		return 0;
	}
	else {
		find_ans(1, n2);
		rep(i, 1, cs){
			int id = anslis[i];
			if (id == 1){
				int si = lis[i].size();
				srep(j, 0, si){
					int x = lis[i][j];
					if (c[x] == 1){
						out[x] = 2;
					}
				}
			}
			else {
				int si = lis[i].size();
				srep(j, 0, si){
					int x = lis[i][j];
					if (c[x] == 2){
						out[x] = 2;
					}
				}
			}
		}
		rep(i, 1, n){
			if (out[i]) continue;
			if (n1) out[i] = 1, n1--;
			else out[i] = 3;
		}
		printf("YES\n");
		rep(i, 1, n) printf("%d", out[i]);
	}
	return 0;
}