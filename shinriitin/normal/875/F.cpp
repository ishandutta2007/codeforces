#include <bits/stdc++.h>

typedef long long ll;

const int max_N=2e5;

int n,m,f[max_N+21];

int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);	
}

bool flag[max_N+21];

struct edge{
	int u,v,w;	
	inline bool operator<(const edge&o)const{
		return w>o.w;	
	}
	inline void init(){
		scanf("%d%d%d",&u,&v,&w);	
	}
}e[max_N+21];

ll ans;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<=m;++i)e[i].init();
	std::sort(e+1,e+1+m);
	for(int i=1;i<=m;++i){
		int x=find(e[i].u),y=find(e[i].v);
		if(x==y){
			if(flag[x])continue;
			flag[x]=1;
		}
		else{
			if(flag[x]&&flag[y])continue;
			f[x]=y,flag[y]|=flag[x];
		}
		ans+=e[i].w;
	}
	printf("%I64d\n",ans);
	return 0;	
}