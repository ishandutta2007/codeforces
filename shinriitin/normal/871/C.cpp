#include <bits/stdc++.h>

#define pb push_back

const int max_N=2e5,mod=1e9+7;

int n,cnt,ans,siz,pw[max_N+21];

bool flag;

std::unordered_map<int,int>xmap,ymap;

inline int xid(int x){
	int res=xmap[x];
	if(!res)res=xmap[x]=++cnt;
	return res;	
}

inline int yid(int y){
	int res=ymap[y];
	if(!res)res=ymap[y]=++cnt;
	return res;	
}

std::vector<int>vec[max_N+21];

bool vis[max_N+21];

void dfs(int x,int p=0){
	vis[x]=1;
	++siz;	
	for(auto&y:vec[x])if(y!=p){
		if(!vis[y])dfs(y,x);
		else flag=0;	
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;++i){
		scanf("%d%d",&x,&y);
		x=xid(x),y=yid(y);
		vec[x].pb(y),vec[y].pb(x);
	}
	pw[0]=1;
	for(int i=1;i<=cnt;++i)pw[i]=(pw[i-1]<<1)%mod;
	ans=1;
	for(int i=1;i<=cnt;++i)if(!vis[i]){
		siz=0,flag=1;
		dfs(i);
		ans=1ll*ans*(pw[siz]-flag+mod)%mod;
	}
	printf("%d\n",ans);
	return 0;	
}