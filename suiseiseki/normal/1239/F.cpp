#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i <= (b); ++ i)
#define per(i,a,b) for(int i = (a); i >= (b); -- i)
#define pb push_back
#define Pii pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N=500010;
int T,n,m,d[N],nst[N],pre[N],dep[N];
vector<int> G[N];
int rt;
bool vis[N];
bool fd121(int st){
	queue<int> q;
	memset(vis,0,(n+1)*sizeof(bool));
	q.push(st);
	vis[st]=1;
	pre[st]=-1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(u!=st&&d[u]%3==1&&dep[u]<n-1){
			while(!q.empty()){
				q.pop();
			}
			while(~u){
				nst[u]=1;
				u=pre[u];
			}
			return 1;
		}
		for(int v:G[u]){
			if(!vis[v]){
				pre[v]=u;
				vis[v]=1;
				q.push(v);
			}
		}
	}
	return 0;
}
bool dfs1(int u){
	vis[u]=1;
	int MX=-1;
	for(int v:G[u]){
		if(vis[v]&&dep[v]<dep[u]-1&&(MX==-1||dep[v]>dep[MX])){
			MX=v;
		}
	}
	if((~MX)&&dep[u]-dep[MX]+1<n&&d[MX]%3==2){
		while(u!=pre[MX]){
			nst[u]=1;
			u=pre[u];
		}
		return 1;
	}
	for(int v:G[u]){
		if(!vis[v]){
			dep[v]=dep[u]+1;
			pre[v]=u;
			if(dfs1(v)){
				return 1;
			}
		}
	}
	return 0;
}
void dfs2(int u){
	vis[u]=1;
	for(int v:G[u]){
		if(!vis[v]){
			dfs2(v);
		}
	}
}
void is122(int rt){
	int tim=0;
	memset(vis,0,(n+1)*sizeof(bool));
	vis[rt]=nst[rt]=1;
	sort(G[rt].begin(),G[rt].end(),[&](int u,int v){return dep[u]<dep[v];});
	for(int v:G[rt]){
		if(!vis[v]&&dep[v]>1&&tim<2){
			int now=v;
			while(now!=rt){
				nst[now]=1;
				now=pre[now];
			}
			tim++;
			if(tim==2){
				break;
			}
			dfs2(v);
		}
	}
}
void output(){
	int tmp=0;
	for(int i=1;i<=n;i++){
		tmp+=nst[i];
	}
	if(tmp==0||tmp==n){
		puts("No");
		return;
	}
	puts("Yes");
	printf("%d\n",n-tmp);
	for(int i=1;i<=n;i++){
		if(!nst[i]){
			printf("%d ",i);
		}
	}
	puts("");
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		int u,v;
		rep(i,1,m){
			scanf("%d%d",&u,&v);
			G[u].pb(v);
			G[v].pb(u);
			d[u]++;
			d[v]++;
		}
		vector<int> nd(3,0);
		if(n==1){
			goto OUTPUT;
		}
		rep(i,1,n){
			nd[d[i]%3]++;
		}
		rep(i,1,n){
			if(d[i]%3==0){
				nst[i]=1;
				goto OUTPUT;
			}
		}
		for(rt=1;rt<=n&&d[rt]%3!=1;rt++);
		if(rt<=n&&fd121(rt)){
			goto OUTPUT;
		}
		memset(vis,0,(n+1)*sizeof(bool));
		memset(pre,-1,(n+1)*sizeof(int));
		if(dfs1(rt<=n?rt:1)){
			goto OUTPUT;
		}
		if(d[rt]%3==1){
			is122(rt);
		}
OUTPUT: output();
        rep(i,1,n){
			G[i].clear();
			vis[i]=dep[i]=d[i]=nst[i]=0;
		}
    }
    return 0;
}