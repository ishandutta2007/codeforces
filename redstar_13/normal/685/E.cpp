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

#define NN 1010
int mn[NN][NN];
#define MM 200200
int E, head[MM], tail[MM], nxt[MM*3], from[MM*3], to[MM*3], mx[MM*3], id[MM*3];
int ans[MM];

void add(int l, int u, int v, int r=0, int i=0){
	if(!head[l]) head[l]=tail[l]=++E;
	else tail[l]=nxt[tail[l]]=++E;
	from[E]=u;
	to[E]=v;
	mx[E]=r;
	id[E]=i;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n, m, q, u, v, l, r;
	cin >> n >> m >> q;
	
	for(int i=1, u, v; i<=m; i++){
		gn(u, v);
		add(i, u, v);
		add(i, v, u);
	}
	
	for(int i=1; i<=q; i++){
		gn(l, r), gn(u, v);
		add(l, u, v, r, i);
	}
	
	memset(mn, 0x3f, sizeof(mn));
	
	for(int i=MM; --i; ) if(head[i]){
		int e=head[i];
		while(e){
			if(id[e]) ans[id[e]]=mn[from[e]][to[e]]<=mx[e];
			else {
				mn[from[e]][to[e]]=i;
				for(int u=1; u<=n; u++) smin(mn[from[e]][u], mn[to[e]][u]);
			}
			e=nxt[e];
		}
	}
	
	for(int i=1; i<=q; i++) puts(ans[i] ? "Yes" : "No");
	
	return 0;
}