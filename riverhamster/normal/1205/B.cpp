#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void in(T &x){ //Read Positive Integer.
	char ch; x = 0;
	// int f = 1;
	while(isspace(ch = getchar()));
	// if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	// x *= f;
}
const int N = 100005;
ll a[N];
int haveBit[N];
int to[N], nt[N], hd[N], tot = 0;
bool vis[N];
int start = 0;
vector<int> Vis;

void addedge(int x, int y){to[tot] = y; nt[tot] = hd[x]; hd[x] = tot; ++tot;}

int dis[N];
void bfs(int S, int del){
	queue<int> q;
	memset(dis, -1, sizeof dis);
	dis[S] = 0; q.push(S);
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int i=hd[x]; i!=-1; i=nt[i]){
			if(i != del && i != (del ^ 1) && dis[to[i]] == -1)
				dis[to[i]] = dis[x] + 1, q.push(to[i]);
		}
	}
}

set<pair<int, int> > Edge;

int main(){
	// File("cf1205b");
	memset(hd, -1, sizeof hd);
	int n; in(n);
	for(int i=1; i<=n; i++) in(a[i]);
	for(int i=0; i<63; i++){
		int cnt = 0;
		for(int j=1; j<=n; j++) if((a[j] >> i) & 1) haveBit[++cnt] = j;
		if(cnt >= 3){
			puts("3"); return 0;
		}
		else if(cnt == 2){
			int x = haveBit[1], y = haveBit[2];
			if(!Edge.count(make_pair(x, y))){
				Edge.insert(make_pair(x, y)); Edge.insert(make_pair(y, x));
				addedge(haveBit[1], haveBit[2]), addedge(haveBit[2], haveBit[1]);
			}
		}
	}
	int ans = 0x7fffffff;
	for(int x=1; x<=n; x++){
		for(int i=hd[x]; i!=-1; i=nt[i]){
			bfs(x, i);
			if(dis[to[i]] != -1) ans = min(ans, dis[to[i]] + 1);
		}
	}
	if(ans == 0x7fffffff) puts("-1");
	else printf("%d\n", ans);
	return 0;
}