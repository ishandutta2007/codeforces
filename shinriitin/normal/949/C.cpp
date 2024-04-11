#include <bits/stdc++.h>

const int max_N = 1e5 + 21;

std::vector<int>vec[max_N];

int n,m,h,u[max_N];

int dfn[max_N],low[max_N],cnt;

int sccno[max_N],scc_cnt;

int scc_deg[max_N],scc_siz[max_N];

int st[max_N],top;

void dfs(int x){
	st[++top]=x;
	dfn[x]=low[x]=++cnt;
	for(auto&y:vec[x]){
		if(!dfn[y]){
			dfs(y);
			low[x]=std::min(low[x],low[y]);
		}
		else if(!sccno[y]){
			low[x]=std::min(low[x],dfn[y]);	
		}
	}
	if(dfn[x]==low[x]){
		sccno[x]=++scc_cnt;
		scc_siz[scc_cnt]=1;
		while(st[top]!=x){
			sccno[st[top--]]=scc_cnt;
			++scc_siz[scc_cnt];
		}
		--top;
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&h);
	for(int i=1;i<=n;++i)scanf("%d",u+i);
	while(m--){
		int a,b; scanf("%d%d",&a,&b);	
		if((u[a]+1)%h==u[b])vec[a].push_back(b);
		if((u[b]+1)%h==u[a])vec[b].push_back(a);
	}
	for(int i=1;i<=n;++i)if(!dfn[i])dfs(i);
	for(int i=1;i<=n;++i)
		for(auto&j:vec[i]){
			if(sccno[i]!=sccno[j])
				++scc_deg[sccno[i]];
			}
	int ans=n+1,ansi=-1;
	for(int i=1;i<=scc_cnt;++i)
		if(!scc_deg[i]&&ans>scc_siz[i]){
			ans=scc_siz[i];
			ansi=i;
		}
	printf("%d\n",ans);
	int tot=0;
	for(int i=1;i<=n;++i)
		if(sccno[i]==ansi){
			printf("%d%c",i," \n"[++tot==ans]);	
		}
	return 0;
}