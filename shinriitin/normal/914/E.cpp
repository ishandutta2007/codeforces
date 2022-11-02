#include <bits/stdc++.h>

const int max_N = 2e5 + 21;

const int max_S = 1<<20;

using ll = long long;

bool vis[max_N];

char s[max_N];

ll ans[max_N];

std::vector<int>vec[max_N],mem[max_N];

int n,rt,siz[max_N],max[max_N],dis[max_N],cnt[max_S];

int find_p(int x,int p,int Sum){
	siz[x]=1,max[x]=0;
	for(auto&y:vec[x])
		if(y!=p&&!vis[y]){
			siz[x]+=find_p(y,x,Sum);
			max[x]=std::max(max[x],siz[y]);
		}
	max[x]=std::max(max[x],Sum-siz[x]);
	if(max[x]<max[rt])rt=x;
	return siz[x];
}

void dfs1(int x,int p,std::vector<int>&mem){
	mem.push_back(x);
	dis[x]=dis[p]^(1<<(s[x]-'a'));
	++cnt[dis[x]];
	for(auto&y:vec[x])
		if(y!=p&&!vis[y]){
			dfs1(y,x,mem);
		}
}

ll dfs2(int x,int p,int rt){
	ll res=0;
	res+=cnt[dis[x]^rt];
	for(int i=0;i<20;++i)
		res+=cnt[dis[x]^rt^(1<<i)];
	for(auto&y:vec[x])
		if(y!=p&&!vis[y]){
			res+=dfs2(y,x,rt);
		}
	ans[x]+=res;
	return res;
}

void solve(int x){
	vis[x]=1;
	++cnt[dis[x]=0];
	mem[x]={x};
	for(auto&y:vec[x])if(!vis[y]){
		dfs1(y,x,mem[y]);
	}
	ll tmp=0;
	for(auto&y:vec[x])if(!vis[y]){
		for(auto&i:mem[y])--cnt[dis[i]];
		tmp+=dfs2(y,x,1<<(s[x]-'a'));
		for(auto&i:mem[y]){
			++cnt[dis[i]];
			int t=dis[i]^(1<<(s[x]-'a'));
			if(!t||t==(t&-t))++tmp;
			mem[x].push_back(i);
		}
		mem[y].clear();
	}
	ans[x]+=tmp/2+1;
	for(auto&i:mem[x])--cnt[dis[i]];
	mem[x].clear();
	for(auto&y:vec[x])if(!vis[y]){
		rt=0;
		find_p(y,x,siz[y]);
		solve(rt);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	scanf("%s",s+1);
	max[rt=0]=n+1;
	find_p(1,0,n);
	solve(rt);
	for(int i=1;i<=n;++i){
		printf("%I64d%c",ans[i]," \n"[i==n]);
	}
	return 0;
}