#include<bits/stdc++.h>
#define mod 1000000007
#define INPUT_LEN 1000
#define NN 200001
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
char gchar(){static char tbuf1[INPUT_LEN],*tmp_st=tbuf1,*tmp_ed=tbuf1;if(tmp_st==tmp_ed){int len=fread(tbuf1,1,INPUT_LEN,stdin);if(len==0)return-1;tmp_ed=tbuf1+len;tmp_st=tbuf1;}return*(tmp_st++);}
inline bool gn(int&x){char c,sg=0;while(c=gchar(),(c>'9'||c<'0')&&c!='-'&&~c);if(c==-1)return 0;for((c=='-'?sg=1,c=gchar():0),x=0;c>='0'&&c<='9';c=gchar())x=(x<<1)+(x<<3)+c-'0';if(sg)x=-x;return 1;}
inline void print(int x){if(x<0){putchar('-');return print(-x);}if(x<10){putchar('0'+x);return;}print(x/10);putchar(x%10+'0');}
template<class T>inline void printsp(T x){print(x);putchar(' ');}

inline int inv(int x) {
	if(x<2) return x;
	return (INT)mod/x*(mod-inv(mod%x))%mod;
}

inline pii operator * (pii a, int x) {
	if(x%mod==0) return pii(a.x, a.y+1);
	return pii((INT)a.x*x%mod, a.y);
}

inline pii operator / (pii a, int x) {
	if(x%mod==0) return pii(a.x, a.y-1);
	return pii((INT)a.x*inv(x)%mod, a.y);
}

int dp[NN];
vector<int> adj[NN];
pii all[NN], tmp;

inline void dfs(int u) {
	all[u]=pii(1, 0);
	for(int v: adj[u]) {
		dfs(v);
		all[u]=all[u]*(dp[v]+1);
	}
	dp[u]=all[u].y ? 0 : all[u].x;
}

inline void rdfs(int u, int up=0) {
	dp[u]=(INT)dp[u]*(up+1)%mod;
	all[u]=all[u]*(up+1);
	for(int v: adj[u]) {
		tmp=all[u]/(dp[v]+1);
		rdfs(v, tmp.y ? 0 : tmp.x);
	}
}

int main() {
	int n; gn(n);
	for(int i=2, pa; i<=n; i++) {
		gn(pa);
		adj[pa].push_back(i);
	}
	dfs(1), rdfs(1);
	for(int i=1; i<=n; i++) printsp(dp[i]);
}