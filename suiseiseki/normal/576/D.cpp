#include <queue>
#include <bitset>
#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=150;
const int Maxm=150;
const int Inf=0x3f3f3f3f;
int n,m;
struct Edge{
	int u,v;
	int d;
	friend bool operator <(Edge p,Edge q){
		return p.d<q.d;
	}
}edge[Maxm+5];
int dis[Maxn+5];
struct Matrix{
	bitset<Maxn+5> a[Maxn+5];
	friend bitset<Maxn+5> operator *(bitset<Maxn+5> a,Matrix b){
		bitset<Maxn+5> ans;
		for(int i=0;i<n;i++){
			ans[i]=(a&b.a[i]).any();
		}
		return ans;
	}
	friend Matrix operator *(Matrix a,Matrix b){
		Matrix ans;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a.a[i][j]){
					ans.a[i]=ans.a[i]|b.a[j];
				}
			}
		}
		return ans;
	}
}a;
void quick_power(Matrix a,int b,bitset<Maxn+5> &ans){
	while(b){
		if(b&1){
			ans=ans*a;
		}
		a=a*a;
		b>>=1;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].d);
		edge[i].u--;
		edge[i].v--;
	}
	sort(edge+1,edge+1+m);
	int last=0;
	bitset<Maxn+5> vis;
	vis[0]=1;
	int ans=Inf;
	for(int i=1;i<=m;i++){
		if(edge[i].d>=ans){
			break;
		}
		quick_power(a,edge[i].d-last,vis);
		last=edge[i].d;
		queue<int> q;
		a.a[edge[i].v][edge[i].u]=1;
		for(int j=0;j<n;j++){
			if(vis[j]){
				dis[j]=0;
				q.push(j);
			}
			else{
				dis[j]=Inf;
			}
		}
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int v=0;v<n;v++){
				if(a.a[v][u]){
					if(dis[v]==Inf){
						dis[v]=dis[u]+1;
						q.push(v);
					}
				}
			}
		}
		ans=min(ans,dis[n-1]+edge[i].d);
	}
	if(ans==Inf){
		puts("Impossible");
	}
	else{
		printf("%d\n",ans);
	}
	return 0;
}