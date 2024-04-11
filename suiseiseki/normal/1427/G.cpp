#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=(1<<16);
const int Block=(1<<8)-1;
const int d[4]={1,256,-1,-256};
int n;
int a[Maxn];
bool mp[4][Maxn];
int lis[1024],len;
bool vis[Maxn];
bool S[Maxn],T[Maxn];
bool dfs(const int &u,const bool *g){
	vis[u]=1;
	if(g[u]){
		return 1;
	}
	for(int i=0;i<4;i++){
		if(!mp[i][u]){
			continue;
		}
		int v=u+d[i];
		if(g==S&&mp[i^2][v]){
			continue;
		}
		if(vis[v]){
			continue;
		}
		if(dfs(v,g)){
			if(mp[i^2][v]){
				mp[i][u]=0;
			}
			else{
				mp[i^2][v]=1;
			}
			return 1;
		}
	}
	return 0;
}
inline bool cmp(const int &p,const int &q){
	return a[p]<a[q];
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int id=(i<<8)|j;
			scanf("%d",&a[id]);
			if(a[id]>0){
				lis[len++]=id;
				T[id]=1;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int u=(i<<8)|j;
			if(a[u]==-1){
				continue;
			}
			for(int k=0;k<4;k++){
				int v=u+d[k];
				if((v>>8)>=n||(v&Block)>=n||(v>>8)<0||(v&Block)<0||a[v]==-1){
					continue;
				}
				mp[k][u]=1;
			}
		}
	}
	sort(lis,lis+len,cmp);
	ll ans=0;
	int flow=0;
	for(int i=0;i<len-1;i++){
		int id=lis[i];
		while(dfs(id,S)){
			flow--;
			memset(vis,0,sizeof vis);
		}
		T[id]=0;
		S[id]=1;
		memset(vis,0,sizeof vis);
		for(int j=0;j<=i;j++){
			int u=lis[j];
			while(dfs(u,T)){
				flow++;
				memset(vis,0,sizeof vis);
			}
		}
		memset(vis,0,sizeof vis);
		ans+=1ll*(a[lis[i+1]]-a[id])*flow;
	}
	printf("%lld\n",ans);
	return 0;
}