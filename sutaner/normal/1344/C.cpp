#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x, g) for (register int i = g.h[x]; i; i = g.e[i].next)
#define pii pair<int, int>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 400020
#define maxm 400020
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

int n, m;
int lis[maxn], cs = 0;

struct G{
	struct edge{
		int next, to;
		edge(int next, int to) : next(next), to(to){}
		edge(){}
	}e[maxm << 1];
	int cnt = 1, h[maxn], out[maxn], in[maxn];
	void Add_Edge(int x, int y){
		e[++cnt] = edge(h[x], y);
		h[x] = cnt;
		out[x]++, in[y]++;
	}
}g, ig;

bool cmp(int i, int j){
	return g.in[i] < g.in[j];
}


int bfs[maxn], head = 0, tail = 0;
bool topo(){
	//sort(lis + 1, lis + 1 + cs, cmp);
	rep(i, 1, cs){
		int x = lis[i];
		if (!g.in[x]) bfs[++head] = x;
	}
	while (head > tail){
		int x = bfs[++tail];
		erep(i, x, g){
			int op = g.e[i].to;
			g.in[op]--;
			if (!g.in[op]) bfs[++head] = op;
		}
	}
	return head == cs;
}

bool app[maxn], vis[maxn];

set<int> pre[maxn], suf[maxn];
void dfsp(int x){
	erep(i, x, g){
		int op = g.e[i].to;
		if (suf[op].count(x)) {
			suf[op].erase(x);
			if (vis[op] && suf[op].empty()) dfsp(op); 
		}
	}
}
void dfss(int x){
	erep(i, x, ig){
		int op = ig.e[i].to;
		if (pre[op].count(x)) {
			pre[op].erase(x);
			if (vis[op] && pre[op].empty()) dfss(op);
		}
	}
}

char ans[maxn];

int main(){
	
		//freopen(".in", "r", stdin);
		
	// Not appear 
	int x, y;
	read(n), read(m);
	rep(i, 1, m) read(x), read(y), app[x] = 1, app[y] = 1, g.Add_Edge(x, y), ig.Add_Edge(y, x);
	rep(i, 1, n) ans[i] = 'E';
	rep(i, 1, n) if (!app[i]) ans[i] = 'A'; else lis[++cs] = i;
	if (!topo()) {
		printf("-1\n");
		return 0;
	}
	sort(lis + 1, lis + 1 + cs);
	per(i, cs, 1){
		int x = lis[i];
		erep(i, x, g){ 
			int op = g.e[i].to;
			pre[x].insert(op);
		} 
		erep(i, x, ig){ 
			int op = ig.e[i].to;
			suf[x].insert(op);
		} 
	}
	per(i, cs, 1){
		int x = lis[i]; 
		vis[x] = 1;
		if (pre[x].empty() && suf[x].empty()) ans[x] = 'A';
		if (pre[x].empty()) dfss(x);
		if (suf[x].empty()) dfsp(x);
	}
	int ct = 0;
	rep(i, 1, n) if (ans[i] == 'A') ct++;
	printf("%d\n%s", ct, ans + 1);
	return 0;
}