#include<bits/stdc++.h>
 
const int maxn = 2002;
 
typedef long long ll;
 
const ll inf = 1e18;
 
int n,m,s,t,type;
 
template<typename t1,typename t2>
 
inline std::ostream& operator << (std::ostream&cout,const std::pair<t1,t2>&pr){
 
	return cout << '(' << pr.first << ',' << pr.second << ')';
 
}
 
struct T{ int to,nxt,v; }way[100100 << 1];;
 
int h[maxn],num;
 
inline void adde(int x,int y,int v){
 
	way[++num]={y,h[x],v},h[x]=num;
 
	way[++num]={x,h[y],v},h[y]=num;
 
}
 
int vis[maxn],p[maxn];
 
ll dis1[maxn],dis2[maxn];
 
inline void dij(int s,ll * dis){
 
	typedef std::pair<ll,int> pr;
 
	std::priority_queue<pr,std::vector<pr>,std::greater<pr>> q;
 
	for(int i = 1;i <= n; ++i) q.push(pr(dis[i] = inf,i)),vis[i] = 0;
 
	const auto relax = [&](int x,ll v){ if(v < dis[x]) q.push(pr(dis[x] = v,x)); };
 
	for(relax(s,0);!q.empty();){
 
		pr t = q.top(); q.pop(); int x = t.second;
 
		if(vis[x]) continue; vis[x] = 1;
 
		for(int i = h[x];i;i=way[i].nxt) relax(way[i].to,dis[x] + way[i].v);
 
	}
	
}
 
int cnt[maxn][maxn];
 
ll sum[maxn][maxn];
 
ll dp0[maxn][maxn];
 
ll dp1[maxn][maxn];
 
inline void up(ll & x,ll y){
 
	if(x < y)x = y;
 
}
 
template<typename T>
 
inline ll getsum(T a,int x1,int x2,int y1,int y2){
 
	return x1 <= x2 && y1 <= y2 ? a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1] : 0;
 
}
 
int main(){
 
	std::ios::sync_with_stdio(false),std::cin.tie(0);
 
	std::cin >> n >> m >> s >> t;
 
	for(int i = 1;i <= n;++i) std::cin >> p[i];
 
	for(int i = 1,x,y,v;i<=m;++i) std::cin >> x >> y >> v,adde(x,y,v);
 
	dij(s,dis1); dij(t,dis2); std::vector<ll> v1,v2;
 
	for(int i = 1;i <= n;++i) v1.push_back(dis1[i]),v2.push_back(dis2[i]);
 
	std::sort(v1.begin(),v1.end()), v1.erase(std::unique(v1.begin(),v1.end()),v1.end());
 
	std::sort(v2.begin(),v2.end()), v2.erase(std::unique(v2.begin(),v2.end()),v2.end());
 
	for(int i = 1;i <= n;++i){
 
		int x = std::lower_bound(v1.begin(),v1.end(),dis1[i]) - v1.begin() + 1;
 
		int y = std::lower_bound(v2.begin(),v2.end(),dis2[i]) - v2.begin() + 1;
 
		++ cnt[x][y]; sum[x][y] += p[i];
 
	}
 
	int o1 = v1.size(),o2 = v2.size();
 
	for(int i = 1;i <= o1;++i) for(int j = 1;j <= o2;++j)
 
		cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1],
 
		sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
 
	for(int i = o1;i >= 0;--i){
 
		for(int j = o2;j >= 0;--j){
 
			if(i == o1 || j == o2) dp0[i][j] = dp1[i][j] = 0;
 
			else{
 
				dp0[i][j] = dp1[i][j] = -inf;
 
				if(dp0[i + 1][j] > -inf) up(dp0[i][j],dp0[i + 1][j] + getsum(sum,i + 1,i + 1,j + 1,o2));
 
				if(dp1[i][j + 1] > -inf) up(dp1[i][j],dp1[i][j + 1] + getsum(sum,i + 1,o1,j + 1,j + 1));
 
				if(dp1[i + 1][j] > -inf && getsum(cnt,i + 1,i + 1,j + 1,o2))
 
					up(dp0[i][j],-dp1[i + 1][j] + getsum(sum,i + 1,i + 1,j + 1,o2));
 
				if(dp0[i][j + 1] > -inf && getsum(cnt,i + 1,o1,j + 1,j + 1))
 
					up(dp1[i][j],-dp0[i][j + 1] + getsum(sum,i + 1,o1,j + 1,j + 1));
 
			}
 
		}
 
	}
 
	if(dp0[0][0] < 0) std::cout << "Cry" << '\n';
 
	if(dp0[0][0] == 0) std::cout << "Flowers" << '\n';
 
	if(dp0[0][0] > 0) std::cout << "Break a heart" << '\n';
 
}