#include <queue>
#include <cstdio>
#include <vector>
typedef long long ll;
const int Maxn=1000;
const int Inf=0x3f3f3f3f;
int n,m;
int a[Maxn+5],b[Maxn+5];
std::vector<int> edge[Maxn+5];
int pre[Maxn+5];
ll dis[Maxn+5];
bool vis[Maxn+5];
bool check(int x){
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	vis[1]=1;
	ll now=x,tot=1;
	while(tot<n){
		std::queue<int> q;
		for(int i=1;i<=n;i++){
			pre[i]=0;
			dis[i]=0;
			if(vis[i]){
				q.push(i);
				dis[i]=now;
			}
		}
		int x=0,y=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int i=0;i<(int)edge[u].size();i++){
				int v=edge[u][i];
				if(!vis[v]){
					if(dis[u]<=a[v]){
						continue;
					}
					if(pre[v]==0){
						pre[v]=u;
						dis[v]=dis[u]+b[v];
						q.push(v);
					}
					else if(v!=pre[u]){
						x=u,y=v;
						goto OUT;
					}
				}
				else if(!vis[u]&&v!=pre[u]){
					x=u,y=v;
					goto OUT;
				}
			}
		}
		OUT:;
		if(x==0){
			return 0;
		}
		for(int u=x;u;u=pre[u]){
			if(!vis[u]){
				vis[u]=1;
				now+=b[u];
				tot++;
			}
		}
		for(int u=y;u;u=pre[u]){
			if(!vis[u]){
				vis[u]=1;
				now+=b[u];
				tot++;
			}
		}
	}
	return 1;
}
void solve(){
	int left=Inf,right=0;
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++){
		scanf("%d",&a[i]);
		left=std::min(left,a[i]);
		right=std::max(right,a[i]);
	}
	right++;
	for(int i=2;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i++){
		edge[i].clear();
	}
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		edge[u].push_back(v),edge[v].push_back(u);
	}
	while(left<right){
		int mid=(left+right)>>1;
		if(check(mid)){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	printf("%d\n",left);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}