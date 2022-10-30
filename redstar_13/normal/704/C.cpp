#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3fLL
#define MOD 1000000007
#define pb push_back
#define sq(x) ((x)*(x))
#define x first
#define y second
#define eps 1e-8
#define bpt(x) (__builtin_popcount(x))
#define bptl(x) (__builtin_popcountll(x))
#define bit(x, y) (((x)>>(y))&1)
#define bclz(x) (__builtin_clz(x))
#define bclzl(x) (__builtin_clzll(x))
#define bctz(x) (__builtin_ctz(x))
#define bctzl(x) (__builtin_ctzll(x))

using namespace std;
typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef pair<pii, int> pi3;
typedef double DO;

template<typename T, typename U> inline void smin(T &a, U b) {if (a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, U b) {if (a<b) a=b;}

template<typename T> inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}
template<class T, class T1>inline void gn(T &x, T1 &y) {gn(x); gn(y);}
template<class T, class T1, class T2>inline void gn(T &x, T1 &y, T2 &z) {gn(x); gn(y); gn(z);}
template<typename T> inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}
template<typename T> inline void println(T x) {print(x), putchar('\n');}
template<typename T> inline void printsp(T x) {print(x), putchar(' ');}
template<class T, class T1> inline void print(T x, T1 y) {printsp(x), println(y);}
template<class T, class T1, class T2> inline void print(T x, T1 y, T2 z) {printsp(x), printsp(y), println(z);}

int power(int a, int b, int m, int ans=1) {
	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
	return ans;
}

#define NN 100100
VI val[NN];
VI num[NN];
VI adj[NN];
int vst[NN];

VI vec;
void dfs(int u){
	vec.pb(u);
	vst[u]=1;
	for(int i=0; i<adj[u].size(); i++){
		int v=adj[u][i];
		if(vst[v]) continue;
		dfs(v);
	}
}

vector <pii> P;
int dp[NN][2][2];
int ddp[NN][2][2][2];
int DP[NN][2];

inline void add(int &a, int b){
	a+=b;
	if(a>=MOD) a-=MOD;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n, m;
	gn(n, m);
	for(int i=1; i<=n; i++){
		int k;
		gn(k);
		int u;
		while(k--){
			gn(u);
			val[i].pb(u);
			if(u>0) num[u].pb(i);
			else num[-u].pb(-i);
		}
	}
	
	int flag=0;
	int tar=1;
	
	int ans=1;
	for(int i=1; i<=m; i++){
		if(num[i].size()>1){
			adj[abs(num[i][0])].pb(abs(num[i][1]));
			adj[abs(num[i][1])].pb(abs(num[i][0]));
		}
		else if(num[i].empty()){
			ans=ans*2%MOD;
		}
	}
	
	if(flag){
		println(power(2, m-1, MOD));
		return 0;
	}
	
	for(int i=1; i<=n; i++){
		if(adj[i].empty()){
			vst[i]=1;
			P.pb(pii(1, (1<<val[i].size())-1));
		}
		else if(!vst[i] && adj[i].size()==1){
			vec.clear();
			dfs(i);
			for(int j=0; j<vec.size(); j++) memset(dp[j], 0, sizeof(dp[j]));
			if(val[vec[0]].size()==2) dp[0][1][1]=1, dp[0][0][0]=1;
			else dp[0][0][0]=1;
			
			for(int j=1; j<vec.size(); j++){
				int fl=0;
				for(int a=0; a<val[vec[j]].size(); a++){
					for(int b=0; b<val[vec[j-1]].size(); b++) if(val[vec[j]][a]==val[vec[j-1]][b]) fl=1;
				}
				if(fl){
					for(int a=0; a<2; a++){
						for(int b=0; b<2; b++){
							add(dp[j][a][0], dp[j-1][a][b]);
							add(dp[j][a^(b==0)^1][1], dp[j-1][a][b]);
						}
					}
				}
				else {
					for(int a=0; a<2; a++){
						for(int b=0; b<2; b++){
							add(dp[j][a^(b==0)][0], dp[j-1][a][b]);
							add(dp[j][a^1][1], dp[j-1][a][b]);
						}
					}
				}
			}
			int v[2]={0, 0};
			for(int k=0; k<1+(val[vec.back()].size()==2); k++) for(int a=0; a<2; a++) for(int b=0; b<2; b++){
				add(v[a^(k && b==0)], dp[vec.size()-1][a][b]);
			}
			P.pb(pii(v[0], v[1]));
		}
	}
	
	for(int i=1; i<=n; i++) if(!vst[i]){
		vec.clear();
		dfs(i);
		
		for(int j=0; j<vec.size(); j++) memset(ddp[j], 0, sizeof(ddp[j]));
		ddp[0][1][1][1]=1;
		ddp[0][0][0][0]=1;
		
		for(int j=1; j<vec.size(); j++){
			int fl=0;
			for(int a=0; a<val[vec[j]].size(); a++){
				for(int b=0; b<val[vec[j-1]].size(); b++) if(val[vec[j]][a]==val[vec[j-1]][b]) fl=1;
			}
			if(fl){
				for(int k=0; k<2; k++){
					for(int a=0; a<2; a++){
						for(int b=0; b<2; b++){
							add(ddp[j][k][a][0], ddp[j-1][k][a][b]);
							add(ddp[j][k][a^(b==0)^1][1], ddp[j-1][k][a][b]);
						}
					}
				}
			}
			else {
				for(int k=0; k<2; k++){
					for(int a=0; a<2; a++){
						for(int b=0; b<2; b++){
							add(ddp[j][k][a^(b==0)][0], ddp[j-1][k][a][b]);
							add(ddp[j][k][a^1][1], ddp[j-1][k][a][b]);
						}
					}
				}
			}
		}
		int ok=0;
		if(vec.size()==1) ok=val[vec[0]][0]==val[vec[0]][1];
		else for(int a=0; a<val[vec[0]].size(); a++){
			for(int b=0; b<val[vec.back()].size(); b++) if(val[vec[0]][a]==val[vec.back()][b]) ok=1;
		}
		int v[]={0, 0};
		for(int k=0; k<2; k++) for(int a=0; a<2; a++) for(int b=0; b<2; b++){
			int kk=k^(!ok);
			add(v[a^(b==0 && kk)], ddp[vec.size()-1][k][a][b]);
		}
		P.pb(pii(v[0], v[1]));
	}
	
	DP[0][0]=1;
	DP[0][1]=0;
	for(int i=0; i<P.size(); i++){
		DP[i+1][0]=((INT)DP[i][0]*P[i].x+(INT)DP[i][1]*P[i].y)%MOD;
		DP[i+1][1]=((INT)DP[i][1]*P[i].x+(INT)DP[i][0]*P[i].y)%MOD;
	}
	
	println((INT)DP[P.size()][tar]*ans%MOD);
	
	return 0;
}