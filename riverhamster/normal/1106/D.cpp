#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <functional>
using namespace std;
const int N = 200005, M = 600005;
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	// register int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
priority_queue<int, vector<int>, greater<int> > q;
bool inq[N];
int to[M], nt[M], hd[N], ans[N], tot = 0;
bool vis[N];
int n, m;
inline void addedge(int x, int y){
	++tot;
	to[tot] = y; nt[tot] = hd[x]; hd[x] = tot;
}
void work(){
	int x = 1, mn;
	for(int i=1; i<=n; i++){
		ans[i] = x; vis[x] = true; inq[x] = false;
		mn = n + 1;
		for(int i=hd[x]; i; i=nt[i])
			if(!vis[to[i]] && to[i] < mn && to[i] != x) mn = to[i];
		if(!q.empty()) mn = min(mn, q.top());
		for(int i=hd[x]; i; i=nt[i])
			if(!vis[to[i]] && to[i] != mn && to[i] != x && !inq[to[i]]) q.push(to[i]), inq[to[i]] = true;
		else{
			x = mn;
			if(!q.empty()) if(x == q.top()) q.pop();
		}
	}
}

int main(){
	// freopen("d.in", "r", stdin);
	// freopen("d.out", "w", stdout);
	int x, y;
	in(n); in(m);
	for(int i=1; i<=m; i++){
		in(x); in(y);
		addedge(x, y); addedge(y, x);
	}
	work();
	for(int i=1; i<=n; i++) printf("%d ", ans[i]);
	return 0;
}