#define inf 0x3f3f3f3f3f3f3f3fLL
#include<bits/stdc++.h>
#define INPUT_LEN 1000
#define NN 222
#define C 26

using namespace std;
typedef long long INT;
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}
char gchar(){static char tbuf1[INPUT_LEN],*tmp_st=tbuf1,*tmp_ed=tbuf1;if(tmp_st==tmp_ed){int len=fread(tbuf1,1,INPUT_LEN,stdin);if(len==0)return-1;tmp_ed=tbuf1+len;tmp_st=tbuf1;}return*(tmp_st++);}
inline bool gn(int&x){char c,sg=0;while(c=gchar(),(c>'9'||c<'0')&&c!='-'&&~c);if(c==-1)return 0;for((c=='-'?sg=1,c=gchar():0),x=0;c>='0'&&c<='9';c=gchar())x=(x<<1)+(x<<3)+c-'0';if(sg)x=-x;return 1;}
inline bool gn(INT&x){char c,sg=0;while(c=gchar(),(c>'9'||c<'0')&&c!='-'&&~c);if(c==-1)return 0;for((c=='-'?sg=1,c=gchar():0),x=0;c>='0'&&c<='9';c=gchar())x=(x<<1)+(x<<3)+c-'0';if(sg)x=-x;return 1;}
inline bool gn(string&s){char c;s.clear();while(c=gchar(),~c&&isspace(c));if(~c)s+=c;while(c=gchar(),~c&&!isspace(c))s+=c;return ~c;}
inline bool gn(char*s){string s1;bool ok=gn(s1);strcpy(s,s1.c_str());return ok;}
inline void print(INT x){if(x<0){putchar('-');return print(-x);}if(x<10){putchar('0'+x);return;}print(x/10);putchar(x%10+'0');}

INT mat[NN][NN], ans[NN][NN], tmp[NN][NN], L;
char s[NN];
int a[NN], que[NN], qf, qb, used, N;

inline void mul(INT a[NN][NN], INT b[NN][NN], INT c[NN][NN]) {
	for(int i=N; i--; ) {
		for(int j=N; j--; ) {
			tmp[i][j]=-inf;
			for(int k=N; k--; ) smax(tmp[i][j], a[i][k]+b[k][j]);
		}
	}
	for(int i=N; i--; ) {
		for(int j=N; j--; ) {
			c[i][j]=tmp[i][j];
		}
	}
}

struct node{
	int nxt[C], fail, cnt;
	inline void clear() {
		fail=-1; cnt=0;
		memset(nxt, -1, sizeof nxt);
	}
} mem[NN];

struct AC_automaton {
	inline int newnode() {
		used++;
		mem[used].clear();
		return used;
	}
	inline void init() {
		used=-1;
		qb=qf=0;
		newnode();
		
		int n; gn(n), gn(L);
		for(int i=1; i<=n; i++) gn(a[i]);
		for(int i=1; i<=n; i++) {
			gn(s);
			insert(a[i]);
		}
		build_fail();
		
		N=used+1;
		for(int u=0, nxt; u<N; u++) {
			for(nxt=0; nxt<N; nxt++) mat[u][nxt]=-inf;
			mat[u][u]=0;
			for(int j=C; j--; ) {
				nxt=find_next(u, j);
				mat[u][nxt]=mem[nxt].cnt;
			}
			for(nxt=0; nxt<N; nxt++) ans[u][nxt]=mat[u][nxt];
		}
		for(L--; L; L>>=1, mul(mat, mat, mat)) if(L&1) mul(ans, mat, ans);
	}
	void insert(int val) {
		int now=0, c;
		for(int i=0; s[i]; i++) {
			c=s[i]-'a';
			if(mem[now].nxt[c]==-1) mem[now].nxt[c]=newnode();
			now=mem[now].nxt[c];
		}
		mem[now].cnt+=val;
	}
	inline int find_next(int p, int c) {
		while(~p && mem[p].nxt[c]==-1) p=mem[p].fail;
		return (~p) ? mem[p].nxt[c] : 0;
	}
	inline void build_fail() {
		int u, nx, now;
		qf=qb=0; que[qb++]=0;
		while(qf<qb) {
			u=que[qf++];
			if(~mem[u].fail) mem[u].cnt+=mem[mem[u].fail].cnt;
			for(int i=C; i--; ) {
				nx=mem[u].nxt[i];
				if(~nx) {
					now=mem[u].fail;
					while(~now && mem[now].nxt[i]==-1) now=mem[now].fail;
					if(~now) mem[nx].fail=mem[now].nxt[i];
					else mem[nx].fail=0;
					que[qb++]=nx;
				}
			}
		}
	}

} ac;

main() {
	ac.init();
	print(*max_element(ans[0], ans[0]+N));
}