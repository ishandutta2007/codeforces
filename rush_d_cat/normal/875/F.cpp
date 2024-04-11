#include <bits/stdc++.h>
using namespace std;
const int N = 200000+10;
int n,m,flag[N];
struct Edge {
	int u,v,w;
	bool operator<(const Edge&o)const{
		return w>o.w;
	}
	void read(){
		scanf("%d%d%d",&u,&v,&w);
	}
} e[N];
 
int par[N];
int find(int x){
	return par[x]==x?x:par[x]=find(par[x]);
}
 
int main() {
	for(int i=0;i<N;i++) par[i]=i;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		e[i].read();
	}
	sort(e+1,e+1+m);
	long long ans=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u, v=e[i].v;
		if(find(u)==find(v)) {
			if(flag[find(u)] == 0) {
				flag[find(u)] = 1;
				ans += e[i].w;
			}
		} else {
			if (flag[find(u)] && flag[find(v)]) continue;
			flag[find(v)] |= flag[find(u)];
			par[find(u)]=find(v); ans+=e[i].w;			
		}
	}
	cout<<ans<<endl;
}