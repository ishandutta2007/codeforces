#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = l;i <= r;++i)
const int maxn = 500500;
const int N = maxn << 1;
typedef int arr[2][2];
int a[N],b[N],ls[N],rs[N],fa[N],rk[N],tot,rt;
int len[N];
int od[N];
int dp[N][2][2];
int max[N];
inline void up(int & x, int y) { if(x < y) x = y; }
inline void up(int x){
	arr & a = dp[x], & b = dp[ls[x]], & c = dp[rs[x]];
	max[x]=std::max(max[ls[x]],max[rs[x]]);
	if(rk[x]) {
		len[x] = len[ls[x]], od[x] = od[ls[x]];
		up(max[x], b[0][0] + c[0][0]);
		up(max[x], b[0][1] + c[0][1]);
		a[0][0] = std::max(b[0][0], c[0][0]);
		a[0][1] = std::max(b[0][1], c[0][1]);
		a[1][0] = std::max(b[1][0], c[0][od[ls[x]]] + len[ls[x]]);
		a[1][1] = std::max(b[1][1], c[0][!od[ls[x]]] + len[ls[x]]);
	} else {
		len[x] = len[ls[x]] + len[rs[x]];
		od[x] = od[ls[x]] ^ od[rs[x]];
		up(max[x], b[1][0] + c[0][0]);
		up(max[x], b[1][1] + c[0][1]);
		a[0][0]=std::max(b[0][0], len[ls[x]] + c[0][od[ls[x]]]);
		a[0][1]=std::max(b[0][1], len[ls[x]] + c[0][!od[ls[x]]]);
		a[1][0]=std::max(c[1][0], len[rs[x]] + b[1][od[rs[x]]]);
		a[1][1]=std::max(c[1][1], len[rs[x]] + b[1][!od[rs[x]]]);
	}
}
inline void set(int x, int v) {
	od[x] = v, len[x] = 1;
	max[x] = v == 0;
	dp[x][0][v] = dp[x][1][v] = 1;
	dp[x][0][!v] = dp[x][1][!v] = -1e6;
	for(;x = fa[x];) up(x);
}
struct T{ int to,nxt,id; }way[maxn << 1];
int id[maxn],h[maxn],t[maxn],num;
std::queue<int> q1[maxn],q2;
inline void adde(int x,int y, int id){
	way[++num]={y,h[x],id},h[x]=num;
	way[++num]={x,h[y],id},h[y]=num;
}
int who[N];
inline void dfs(int x,int f=0){
	for(int i=h[x];i;i=way[i].nxt)if(way[i].to != f)  {
		a[++tot] = x,b[tot] = way[i].to;
		who[way[i].id]=tot;
		q1[x].push(tot),q2.push(tot),dfs(way[i].to,x);
	}
}
inline int pop(std::queue<int> & q){ while(q.size() && fa[q.front()]) q.pop(); return q.size(); }
inline void psbk(std::queue<int> & q){ q.push(q.front()); q.pop(); }
inline void build(){
	while(q2.size() != 1){
		int i = q2.front(); q2.pop();
		if(!fa[i]){
			int x = a[i],y = b[i];
			if(t[y] == 1 && pop(q1[x])){
				if(q1[x].front() == i) psbk(q1[x]);
				pop(q1[x]);
				if(q1[x].size() != 1){
					int j = q1[x].front(); q1[x].pop();
					fa[i] = ++tot; fa[j] = tot;
					a[tot] = a[j]; b[tot] = b[j]; ls[tot] = j; rs[tot] = i;
					id[y] = tot, rk[tot] = 1; --t[x];
					up(tot), q2.push(tot), q1[x].push(tot);
				} else q2.push(i);
			}else if(t[y] == 2 && pop(q1[y])){
				int j = q1[y].front(); q1[y].pop();
				fa[i] = ++tot; fa[j] = tot;
				a[tot] = a[i]; b[tot] = b[j]; ls[tot] = i; rs[tot] = j;
				id[y] = tot; up(tot);
				q2.push(tot); q1[x].push(tot);
			} else q2.push(i);
		}
	}
	rt = q2.front();
}
int n,m;
int v[maxn];
int main(){
	std::ios::sync_with_stdio(false),std::cin.tie(0);
	std::cin >> n;
	for(int i=1,x,y;i<n;++i){
		std::cin >> x >> y >> v[i],adde(x,y,i),++t[x],++t[y];
	}
	dfs(1); build();
	for(int i = 1;i < n;++i) set(who[i], v[i]);
	std::cin >> m;
	for(int i=1,id;i<=m;++i){
		std::cin>>id;
		set(who[id], v[id] ^= 1);
		std::cout << max[rt] << '\n';
	}
}