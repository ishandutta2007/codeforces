#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define maxn 1200020
#define get GET
using namespace std;

int n;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int h[maxn], cnt = 1;
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}
int rec[maxn];
bool vis[maxn], get[maxn];
void dfs(int x, bool c){
	if (vis[x]) return;
	get[x] = c; vis[x] = 1;
	erep(i, x) dfs(e[i].to, c ^ 1); 
}

int main(){
	cin >> n;
	if (!(n & 1)) {
		cout << "First" << endl;
		rep(i, 1, n) cout << i << ' ';
		rep(i, 1, n) cout << i << ' ';
		cout << endl;
	}
	else {
		int x;
		cout << "Second" << endl;
		int _n = (n << 1);
		rep(i, 1, _n) {
			if (i <= n) Add_Edge(i, i + n);
			cin >> x;
			if (rec[x]) Add_Edge(i, rec[x]);
			else rec[x] = i;
		}
		rep(i, 1, _n) dfs(i, 0); 
		//rep(i, 1, _n) cout << get[i] << ' '; cout << endl;
		int res = 0;
		rep(i, 1, _n) if (get[i]) res += i, res %= _n;
		if (res == n) {
			rep(i, 1, _n) if (!get[i]) cout << i << ' ';
			cout << endl;
		}
		else {
			rep(i, 1, _n) if (get[i]) cout << i << ' ';
			cout << endl;
		}
	}
	return 0;
}