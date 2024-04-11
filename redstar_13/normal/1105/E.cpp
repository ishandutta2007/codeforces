#include<bits/stdc++.h>

#define x first
#define y second
#define pb push_back
#define inf 0x3f3f3f3f
#define mod 1000000007
#define sq(x) ((x)*(x))
#define bit(x, y) (((x)>>(y))&1)
#define bctz(x) (__builtin_ctz(x))
#define bclz(x) (__builtin_clz(x))
#define bclzl(x) (__builtin_clzll(x))
#define bctzl(x) (__builtin_ctzl(x))
#define bpt(x) (__builtin_popcount(x))
#define bptl(x) (__builtin_popcountll(x))
#define PQ priority_queue<pii, vector<pii>, greater<pii> >

using namespace std;

typedef double DO;
typedef long long INT;
typedef pair<int, int> pii;
typedef pair<pii, int> pi3;
typedef vector<int> VI;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}
template <class T1, class T2, class T3> inline void gn(T1 &x1, T2 &x2, T3 &x3) {gn(x1, x2), gn(x3);}
template <class T1, class T2, class T3, class T4> inline void gn(T1 &x1, T2 &x2, T3 &x3, T4 &x4) {gn(x1, x2, x3), gn(x4);}
template <class T1, class T2, class T3, class T4, class T5> inline void gn(T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5) {gn(x1, x2, x3, x4), gn(x5);}

template <class T> inline void print(T x) {if(x<0) {putchar('-'); return print(-x);} if(x<10) {putchar('0'+x); return ;} print(x/10); putchar(x%10+'0');}
template <class T> inline void println(T x) {print(x); putchar('\n');}
template <class T> inline void printsp(T x) {print(x); putchar(' ');}
template <class T1, class T2> inline void print(T1 x1, T2 x2) {printsp(x1), println(x2);}
template <class T1, class T2, class T3> inline void print(T1 x1, T2 x2, T3 x3) {printsp(x1), printsp(x2), println(x3);}
template <class T1, class T2, class T3, class T4> inline void print(T1 x1, T2 x2, T3 x3, T4 x4) {printsp(x1), printsp(x2), printsp(x3), println(x4);}
template <class T1, class T2, class T3, class T4, class T5> inline void print(T1 x1, T2 x2, T3 x3, T4 x4, T5 x5) {printsp(x1), printsp(x2), printsp(x3), printsp(x4), println(x5);}

int power(int a, int b, int m, int ans=1) {
	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
	return ans;
}

	const int MV = 50;
	int V;
	int el[MV][MV/30+1];
	int dp[MV];
	int ans;
	int s[MV][MV/30+1];
	vector<int> sol;
	
	void init(int v) {
		V = v; ans = 0;
	}

	void addEdge(int u, int v) {
		if(u > v) swap(u, v);
		if(u == v) return;
		el[u][v/32] |= (1<<(v%32));
	}

	bool dfs(int v, int k) {
		int c = 0, d = 0;
		for(int i=0; i<(V+31)/32; i++) {
			s[k][i] = el[v][i];
			if(k != 1) s[k][i] &= s[k-1][i];
			c += __builtin_popcount(s[k][i]);
		}
		if(c == 0) {
			if(k > ans) {
				ans = k;
				sol.clear();
				sol.push_back(v);
				return 1;
			}
			return 0;
		}
		for(int i=0; i<(V+31)/32; i++) {
			for(int a = s[k][i]; a ; d++) {
				if(k + (c-d) <= ans) return 0;
				int lb = a&(-a), lg = 0;
				a ^= lb;
				while(lb!=1) {
					lb = (unsigned int)(lb) >> 1;
					lg ++;
				}
				int u = i*32 + lg;
				if(k + dp[u] <= ans) return 0;
				if(dfs(u, k+1)) { 
					sol.push_back(v); 
					return 1;
				}
			}
		}
		return 0;
	}
	int solve() {
		for(int i=V-1; i>=0; i--) {
			dfs(i, 1);
			dp[i] = ans;
		}
		return ans;
	}

#define MM 50
int a[MM];
VI adj[MM];
map<string,int> mp;
string ss;
int id[MM][MM];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	for(int i=0;i<MM;i++){
		for(int j=0;j<MM;j++) id[i][j]=1;
	}
	int n,m;
	scanf("%d%d",&n,&m);
	int st=0,t=0;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(x==1){
			for(int i=1;i<=t;i++){
				for(int j=1;j<=t;j++){
				 	id[a[i]][a[j]]=0;
				}
			}
			t=0;
		}
		else{
			cin>>ss;
			if(mp.count(ss)==0){
				mp[ss]=st;
				a[++t]=st;
				st++;
			}
			else a[++t]=mp[ss];
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=t;j++){
		 	id[a[i]][a[j]]=0;
		}
	}
	init(m);
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(i==j) continue;
			if(id[i][j]) addEdge(i,j);
		}
	}
	printf("%d\n",solve());
	return 0;
}