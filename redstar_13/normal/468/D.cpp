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

#define NN 100100
vector <pii> adj[NN];
INT dep[NN];
int sz[NN], mx[NN];

void dfs(int u, int f=0){
	sz[u]=1;
	for(pii p : adj[u]){
		int v=p.x;
		if(v==f) continue;
		dfs(v, u);
		sz[u]+=sz[v];
		smax(mx[u], sz[v]);
	}
}

int n, p[NN];
int id[NN];
set <int> s[NN];

void dfs1(int u, int top, int f){
	id[u]=top;
	s[top].insert(u);
	for(pii p : adj[u]){
		int v=p.x;
		if(v==f) continue;
		dep[v]=dep[u]+p.y;
		dfs1(v, top, u);
	}
}

int tmp[NN];

INT solve(int u){
	int cnt=1;
	id[u]=1;
	s[1].insert(u);
	dep[u]=0;
	
	for(pii p : adj[u]){
		int v=p.x;
		dep[v]=p.y;
		dfs1(v, ++cnt, u);
	}
	
	set <pii> sz_id;
	set <int> mns;
	
	for(int i=1; i<=cnt; i++) sz_id.insert(pii(sz[i]=2*s[i].size(), i));
	for(int i=1; i<=cnt; i++) mns.insert(*s[i].begin());
	
	for(int i=1; i<n; i++){
		int id=::id[i];
		sz_id.erase(pii(sz[id], id));
		sz_id.insert(pii(--sz[id], id));
		int can;
		if(sz_id.rbegin()->x>n-i){
			int num=sz_id.rbegin()->y;
			if(num==1) can=*mns.begin();
			else can=*s[num].begin();
		}
		else {
			auto it=mns.begin();
			if(id>1 && ::id[*it]==id) it++;
			can=*it;
		}
		id=::id[can];
		s[id].erase(can);
		mns.erase(can);
		p[i]=can;
		if(!s[id].empty()) mns.insert(*s[id].begin());
		sz_id.erase(pii(sz[id], id));
		sz_id.insert(pii(--sz[id], id));
	}
	p[n]=*mns.begin();
	INT ans=0;
	for(int i=1; i<=n; i++) ans+=dep[i];
	ans<<=1;
	return ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	cin >> n;
	for(int i=1; i<n; i++){
		int u, v, w; gn(u, v); gn(w);
		adj[u].pb(pii(v, w));
		adj[v].pb(pii(u, w));
	}
	dfs(1);
	
	for(int i=1; i<=n; i++){
		if(sz[i]*2>=n && mx[i]*2<=n){
			cout << solve(i) << endl;
			break;
		}
	}
	
	for(int i=1; i<=n; i++) printf("%d ", p[i]);
	
	return 0;
}