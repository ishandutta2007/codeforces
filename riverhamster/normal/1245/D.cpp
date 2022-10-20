#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
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

const int N = 2005;
struct Edge{
	int x, y;
	ll v;
}e[N*N + N];
bool cmpv(Edge a, Edge b){return a.v < b.v;}
int x[N], y[N];
int c[N], k[N];

int fa[N], rk[N];
int find(int x){
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void merge(int x, int y){
	int fx = find(x), fy = find(y);
	if(fx != fy){
		if(rk[fx] <= rk[fy]) fa[fx] = fy, rk[fy] += (rk[fx] == rk[fy]);
		else fa[fy] = fx;
	}
}

int main(){
	// File("d");
	int n;
	in(n);
	for(int i=1; i<=n; i++)
		in(x[i]), in(y[i]);
	int ec = 0;
	for(int i=1; i<=n; i++){
		in(c[i]);
		e[++ec].x = n+1; e[ec].y = i; e[ec].v = c[i];
	}
	for(int i=1; i<=n; i++) in(k[i]);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++){
			e[++ec].x = i;
			e[ec].y = j;
			e[ec].v = 1LL * (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j]);
			// printf("v %lld\n", e[ec].v);
		}
	sort(e+1, e+1+ec, cmpv);
	for(int i=1; i<=n+1; i++) fa[i] = i;
	static int V = 0, Bu[N], E = 0, Ex[N], Ey[N];
	int tot = 0;
	ll sum = 0;
	for(int i=1; i<=ec && tot < n; i++){
		int fx = find(e[i].x), fy = find(e[i].y);
		if(fx != fy){
			merge(fx, fy);
			sum += e[i].v;
			if(e[i].x == n + 1) Bu[++V] = e[i].y;
			else ++E, Ex[E] = e[i].x, Ey[E] = e[i].y;
			++tot;
		}
	}
	printf("%lld\n", sum);
	printf("%d\n", V);
	for(int i=1; i<=V; i++) printf("%d ", Bu[i]);
	putchar('\n');
	printf("%d\n", E);
	for(int i=1; i<=E; i++) printf("%d %d\n", Ex[i], Ey[i]);
	return 0;
}