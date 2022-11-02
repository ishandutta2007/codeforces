#include<bits/stdc++.h>
#define INPUT_LEN 1000
#define pb push_back
#define MM 1000000
#define NN 500001
#define y second
#define x first

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> pi3;
char gchar(){static char tbuf1[INPUT_LEN],*tmp_st=tbuf1,*tmp_ed=tbuf1;if(tmp_st==tmp_ed){int len=fread(tbuf1,1,INPUT_LEN,stdin);if(len==0)return-1;tmp_ed=tbuf1+len;tmp_st=tbuf1;}return*(tmp_st++);}
inline bool gn(int&x){char c,sg=0;while(c=gchar(),(c>'9'||c<'0')&&c!='-'&&~c);if(c==-1)return 0;for((c=='-'?sg=1,c=gchar():0),x=0;c>='0'&&c<='9';c=gchar())x=(x<<1)+(x<<3)+c-'0';if(sg)x=-x;return 1;}
inline void print(int x){if(x<0){putchar('-');return print(-x);}if(x<10){putchar('0'+x);return;}print(x/10);putchar(x%10+'0');}
template<class T>inline void printsp(T x){print(x);putchar(' ');}
template<class T>inline void println(T x){print(x);putchar('\n');}

bool flag[2][NN];
int x[2][NN], y[2][NN], id[MM];
pi3 edge[MM];
vector<pii> adj[NN], bdj[NN];

int root[NN];
inline int find(int u) {return root[u]==u ? u : root[u]=find(root[u]);}

inline void merge(int u, int v) {
	u=find(u), v=find(v);
	if(u!=v) {
		root[v]=u;
		if(bdj[v].size()>bdj[u].size()) swap(bdj[u], bdj[v]);
		while(!bdj[v].empty()) {
			bdj[u].pb(bdj[v].back());
			bdj[v].pop_back();
		}
	}
}

inline void dfs(int u, int fa=0) {
	int v, I, e;
	for(pii p: adj[u]) {
		v=p.x, I=p.y;
		if(v!=fa) {
			dfs(v, u);
			if(flag[0][I]) {
				while(1) {
					e=bdj[v].back().y;
					if(!flag[1][e]) bdj[v].pop_back();
					else break;
				}
				flag[1][e]=0;
				merge(bdj[v].back().x, v); bdj[v].pop_back();
				printsp(u), printsp(v), printsp(x[1][e]), println(y[1][e]);
			}
			else merge(u, v);
		}
	}
}

main() {
	int n, m=0, ans=0; gn(n);
	for(int i=0, st; i<2; i++) {
		st=i?n:0;
		for(int j=1; j<n; j++) {
			gn(x[i][j]), gn(y[i][j]);
			if(x[i][j]>y[i][j]) swap(x[i][j], y[i][j]);
			id[m]=m;
			edge[m++]=pi3(pii(x[i][j], y[i][j]), st+j);
		}
	}
	sort(id, id+m, [](int u, int v) {return edge[u].x<edge[v].x;});
	
	for(int i=0, j=0, I; i<m; i=j) {
		if(edge[id[i]].x==edge[id[++j]].x) j++;
		if(j-i==1) {
			I=edge[id[i]].y;
			if(I<n) flag[0][I]=true;
			else {
				I-=n, ans++;
				flag[1][I]=true;
				bdj[x[1][I]].pb(pii(y[1][I], I));
				bdj[y[1][I]].pb(pii(x[1][I], I));
			}
		}
	}
	
	for(int i=1; i<n; i++) {
		adj[x[0][i]].pb(pii(y[0][i], i));
		adj[y[0][i]].pb(pii(x[0][i], i));
		root[i]=i;
	}
	root[n]=n;
	
	println(ans);
	dfs(1);
}