#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
void output_no_ans(){
	puts("-1");
	exit(0);
}
int n;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int a[Maxn+5],b[Maxn+5];
int fa[Maxn+5];
int dep[Maxn+5],pos[Maxn+5];
void init_dfs_1(int u){
	dep[u]=dep[fa[u]]+1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u]){
			continue;
		}
		fa[v]=u;
		init_dfs_1(v);
	}
}
bool vis[Maxn+5];
void work_1(){
	int u=pos[1];
	int ans=dep[u];
	while(u!=1){
		vis[u]=1;
		std::swap(b[u],b[fa[u]]);
		u=fa[u];
	}
	vis[1]=1;
	for(int i=1;i<=n;i++){
		if(b[i]!=i){
			return;
		}
	}
	printf("0 %d\n",ans);
	exit(0);
}
std::vector<int> lis[2];
int num;
void get_path(int u){
	if(num==2||(num==1&&fa[u]!=fa[lis[0][0]])){
		output_no_ans();
	}
	while(u){
		lis[num].push_back(u);
		int v=0;
		for(int i=head[u];i;i=nxt[i]){
			if(arrive[i]!=fa[u]&&b[arrive[i]]!=arrive[i]){
				if(v==0){
					v=arrive[i];
				}
				else{
					output_no_ans();
				}
			}
		}
		u=v;
	}
	num++;
}
void init_dfs_2(int u){
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u]){
			continue;
		}
		if(b[v]==v){
			init_dfs_2(v);
		}
		else{
			get_path(v);
		}
	}
}
int tmp[Maxn+5],ori[Maxn+5];
void work_2(){
	int u,v,x;
	if(num==1){
		x=u=fa[lis[0][0]];
		v=lis[0].back();
	}
	else{
		x=fa[lis[0][0]];
		u=lis[0].back();
		v=lis[1].back();
		for(int i=1;i<=(int)lis[1].size();i++){
			lis[0].push_back(lis[1][(int)lis[1].size()-i]);
		}
	}
	memset(tmp,-1,sizeof tmp);
	int k=0,num=lis[0].size();
	for(int i=0;i<num;i++){
		tmp[lis[0][i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(tmp[i]==-1&&b[i]!=i){
			output_no_ans();
		}
	}
	for(int i=0;i<num;i++){
		int val=(tmp[b[lis[0][i]]]+num-i)%num;
		if(i==0){
			k=val;
		}
		else if(k!=val){
			output_no_ans();
		}
	}
	int dis=dep[u]+dep[v]-(dep[x]<<1)+1;
	ll ans;
	if(!vis[x]){
		k=std::min(k,num-k);
		ans=1ll*k*dis;
		while(!vis[x]){
			ans+=2;
			x=fa[x];
		}
		ans+=dep[pos[1]];
	}
	else{
		int cnt=0;
		for(int i=0;i<num;i++){
			cnt+=vis[lis[0][i]];
		}
		if(vis[lis[0][0]]){
			ans=std::min(dis*k,dis*(num-k)-(cnt<<1))+dep[pos[1]];
		}
		else{
			ans=std::min(dis*k-(cnt<<1),dis*(num-k))+dep[pos[1]];
		}
	}
	u=ori[u],v=ori[v];
	if(u>v){
		std::swap(u,v);
	}
	printf("%d %d %lld\n",u,v,ans);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]++;
		ori[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[a[i]]);
		b[a[i]]++;
		pos[b[a[i]]]=a[i];
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u=a[u],v=a[v];
		add_edge(u,v),add_edge(v,u);
	}
	dep[0]=-1;
	init_dfs_1(1);
	work_1();
	init_dfs_2(1);
	work_2();
	return 0;
}