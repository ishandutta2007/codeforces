#include<bits/stdc++.h>
#define INPUT_LEN 1000
#define inf 2000000001
#define pb push_back
#define x first
#define y second
#define MM 60000
#define NN 1001

using namespace std;
typedef pair<int, int> pii;
char gchar(){static char tbuf1[INPUT_LEN],*tmp_st=tbuf1,*tmp_ed=tbuf1;if(tmp_st==tmp_ed){int len=fread(tbuf1,1,INPUT_LEN,stdin);if(len==0)return-1;tmp_ed=tbuf1+len;tmp_st=tbuf1;}return*(tmp_st++);}
inline bool gn(int&x){char c,sg=0;while(c=gchar(),(c>'9'||c<'0')&&c!='-'&&~c);if(c==-1)return 0;for((c=='-'?sg=1,c=gchar():0),x=0;c>='0'&&c<='9';c=gchar())x=(x<<1)+(x<<3)+c-'0';if(sg)x=-x;return 1;}
inline void print(int x){if(x<0){putchar('-');return print(-x);}if(x<10){putchar('0'+x);return;}print(x/10);putchar(x%10+'0');}
template<class T>inline void printsp(T x){print(x);putchar(' ');}
template<class T>inline void println(T x){print(x);putchar('\n');}

int U[30001], V[30001], W[30001];
int head[NN], nxt[MM], to[MM], wei[MM], flag[MM], runs=1, E;
int vst[NN], st[NN], bel[NN], low[NN], Flag[NN], cur;
int ind, cnt, top, n, m, s, t, mn, mn_id;
int q[NN], qf, qb;
int edge[30001], nn;
pii pre[NN];

inline void bfs(int u) {
	q[qb++]=u; vst[u]=0;
	int e, v;
	while(qf<qb) {
		u=q[qf++];
		if(u==t) break;
		for(e=head[u]; ~e; e=nxt[e]) {
			v=to[e];
			if(vst[v]) {
				pre[v]=pii(u, e+2>>1);
				q[qb++]=v;
				vst[v]=0;
			}
		}
	}
}

inline void dfs(int u) {
	vst[u]=0;
	if(u==t) {Flag[u]=cur; return ;}
	for(int e=head[u], v; ~e; e=nxt[e]) if(flag[e]!=runs) {
		v=to[e];
		if(vst[v]) {
			dfs(v);
			if(Flag[v]==cur) Flag[u]=cur;
			if(Flag[v]==cur && bel[u]!=bel[v] && wei[e]<mn) {
				mn=wei[e];
				mn_id=(e>>1)+1;
			}
		}
	}
}

inline void init(int x) {
	E=ind=cnt=0;
	for(int i=1; i<=n; i++) vst[i]=0;
	runs++; flag[x]=flag[x^1]=runs;
}

inline void add(int u, int v, int w) {
	nxt[E]=head[u]; to[E]=v; wei[E]=w; head[u]=E++;
}

inline void Tarjan(int u, int pre=-1) {
	vst[u]=low[u]=++ind;
	st[++top]=u;
	for(int e=head[u]; ~e; e=nxt[e]) if(flag[e]!=runs) {
		int v=to[e];
		if(vst[v]==0) {
			Tarjan(v, e);
			if(low[u]>low[v]) low[u]=low[v];
		}
		else if((e^pre)!=1) {
			if(low[u]>vst[v]) low[u]=vst[v];
		}
	}
	if(vst[u]==low[u]) {
		++cnt;
		while(1) {
			bel[st[top]]=cnt;
			if(st[top--]==u) break;
		}
	}
}

int main() {
	gn(n), gn(m), gn(s), gn(t);
	for(int i=1; i<=n; i++) head[i]=-1, vst[i]=1;
	for(int i=1; i<=m; i++) {
		gn(U[i]), gn(V[i]), gn(W[i]);
		add(U[i], V[i], W[i]);
		add(V[i], U[i], W[i]);
	}
	bfs(s);
	if(vst[t]) {
		puts("0");
		return puts("0");
	}
	
	int ans=inf;
	pair<int, int> kong;
	for(int u=t, one; u!=s; u=pre[u].x) {
		one=pre[u].y;
		if(W[one]>=ans) continue;
		
		init(one-1<<1);
		for(int i=1; i<=n; i++) if(!vst[i]) Tarjan(i);
		if(bel[s]==bel[t]) continue;
		
		mn=inf; cur++;
		dfs(s);
		
		if(vst[t]) {
			ans=W[one];
			kong=pii(one, one);
		}
		else {
			if((long long)W[one]+mn<ans) {
				ans=W[one]+mn;
				kong=pii(one, mn_id);
			}
		}
	}
	if(ans==inf) return puts("-1");
	
	println(ans);
	if(kong.x==kong.y) {
		puts("1");
		print(kong.x);
	}
	else {
		puts("2");
		printsp(kong.x), println(kong.y);
	}
}