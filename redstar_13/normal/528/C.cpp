#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}

int power(int a, int b, int m, int ans=1) {
	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
	return ans;
}

#define NN 100100

multiset<int> adj[NN];
int arr[NN];
queue<int> q;

void find_path(int u){
	while(!adj[u].empty()){
		auto it=adj[u].begin();
		int v=(*it);
		adj[u].erase(it);
		
		it=adj[v].find(u);
		adj[v].erase(it);
		find_path(v);
	}
	q.push(u);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n, m;
	gn(n, m);
	for(int i=1; i<=m; i++) {
		int u, v;
		gn(u, v);
		adj[u].insert(v);
		adj[v].insert(u);
	}
	
	int tot = m;
	int nn = 0;
	
	for(int i=1; i<=n; i++) {
		if(adj[i].size()&1) arr[nn++] = i;
	}
	
	for(int i=0; i<nn; i+=2) {
		int u = arr[i], v = arr[i+1];
		adj[u].insert(v);
		adj[v].insert(u);
		m++;
	}
	
	if(m&1) adj[1].insert(1), adj[1].insert(1), m++;
	
	for(int i=1; i<=n; i++) if(adj[i].size()) find_path(i);
	
	cout<<m<<endl;
	
	int st = 0;
	int pre = q.front(); 
	q.pop();
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(st) printf("%d %d\n", pre, u);
		else printf("%d %d\n", u, pre);
		st ^= 1;
		pre = u;
	}
}