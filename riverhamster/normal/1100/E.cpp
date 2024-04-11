#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 100005;
int hd[N], nt[N], to[N], w[N], deg[N], tot = 0, n, m, id[N];
int ansv[N];
template<typename T> inline void in(T &x){ //Read Positive Integer.
	register char ch; x = 0;
	while(isspace(ch = getchar()));
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
}
inline void addedge(int x, int y, int wt){
	++tot;
	to[tot] = y; nt[tot] = hd[x]; hd[x] = tot; w[tot] = wt;
}

bool check(int val){
	int Index = 0;
	// printf("check %d\n", val);
	memset(deg, 0, sizeof deg); memset(id, 0, sizeof id);
	queue<int> q;
	for(int i=1; i<=tot; i++)
		if(w[i] > val) ++deg[to[i]];
	// printf("deg:");
	// for(int i=1; i<=n; i++)
		// printf("%d ", deg[i]);
	// puts("");
	for(int i=1; i<=n; i++)
		if(deg[i] == 0) q.push(i);
	int x;
	while(!q.empty()){
		x = q.front(); q.pop();
		id[x] = ++Index;
		// printf("%d ", x);
		for(int i=hd[x]; i; i=nt[i]){
			if(w[i] <= val) continue;
			--deg[to[i]];
			if(deg[to[i]] == 0) q.push(to[i]);
		}
	}
	// printf("cnt = %d\n", cnt);
	return n == Index;
}

int main(){
	// freopen("cf1100e.in", "r", stdin);
	// freopen("cf1100e.out", "w", stdout);
	int x, y, W, L = 0, R, mid, ans;
	in(n); in(m);
	for(int i=1; i<=m; i++){
		in(x); in(y); in(W); R = max(R, W);
		addedge(x, y, W);
	}
	while(L <= R){
		mid = (L + R) >> 1;
		if(check(mid)){
			ans = mid;
			R = mid - 1;
		} else L = mid + 1;
	}
	check(ans);
	int ansc = 0;
	for(int from=1; from<=n; from++)
		for(int i=hd[from]; i; i=nt[i])
			if(id[from] > id[to[i]] && w[i] <= ans) ansv[++ansc] = i;
	sort(ansv+1, ansv+1+ansc);
	printf("%d %d\n", ans, ansc);
	for(int i=1; i<=ansc; i++) printf("%d ", ansv[i]);
	putchar('\n');
	return 0;
}