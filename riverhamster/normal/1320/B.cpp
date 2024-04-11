#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
typedef long long ll;
template<typename T> inline void gi(T &x){
	char ch; x = 0;
	int f = 1;
	while(isspace(ch = getchar()));
	if(ch == '-') ch = getchar(), f = -1;
	do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
	x *= f;
}
template<class T> void upmax(T &x, T y){x = x>y ? x : y;}
template<class T> void upmin(T &x, T y){x = x<y ? x : y;}
const int N = 200005;
vector<int> G[N], Gp[N];
int p[N], dis[N];

int main(){
	// File("b");
	int n, m;
	gi(n); gi(m);
	for(int i=1; i<=m; i++){
		int x, y;
		gi(x); gi(y);
		G[y].push_back(x);
		Gp[x].push_back(y);
	}
	int k, mi = 0, mx = 0;
	gi(k);
	for(int i=1; i<=k; i++) gi(p[i]);
	queue<int> q;
	q.push(p[k]);
	memset(dis, -1, sizeof(dis));
	dis[p[k]] = 0;
	while(!q.empty()){
		int x = q.front(); q.pop();
		// printf("dis %d = %d\n", x, dis[x]);
		for(int v : G[x]){
			if(dis[v] == -1){
				dis[v] = dis[x] + 1;
				q.push(v);
			}
		}
	}
	for(int i=1; i<k; i++){
		int c = 0;
		for(int v : Gp[p[i]])
			c += (int)(dis[v] == dis[p[i]] - 1);
		// printf("c = %d\n", c);
		if(dis[p[i+1]] != dis[p[i]] - 1) ++mi, ++mx;
		else if(c > 1) ++mx;
	}
	printf("%d %d\n", mi, mx);
	return 0;
}