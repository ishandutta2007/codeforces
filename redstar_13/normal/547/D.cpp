#include<bits/stdc++.h>

#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}
int power(int a, int b, int m, int ans=1){for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m; return ans;}

#define NN 200200
VI adj[NN];
char col[NN];
int px[NN], py[NN];

void dfs(int u, int c=0){
	col[u]=c ? 'r' : 'b';
	for(int v : adj[u]){
		if(col[v]) continue;
		dfs(v, c^1);
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		int x, y;
		gn(x, y);
		if(px[x]) adj[px[x]].pb(i), adj[i].pb(px[x]), px[x]=0;
		else px[x]=i;
		if(py[y]) adj[py[y]].pb(i), adj[i].pb(py[y]), py[y]=0;
		else py[y]=i;
	}
	
	for(int i=1; i<=n; i++) if(!col[i]) dfs(i);
	
	puts(col+1);
	
	return 0;
}