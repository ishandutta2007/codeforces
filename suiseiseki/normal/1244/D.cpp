#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 100000
#define ll long long
int c[3][Maxn+5];
int p[Maxn+5];
int a[Maxn+5];
int n;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
int dep[Maxn+5];
int num[3];
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int s,t;
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	p[dep[u]]=u;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		dfs(v,u);
	}
}
ll mn(ll a,ll b){
	return a<b?a:b;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<3;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	s=1;
	for(int i=1;i<=n;i++){
		if(dep[i]>dep[s]){
			s=i;
		}
	}
	dfs(s,0);
	t=s;
	for(int i=1;i<=n;i++){
		if(dep[i]>dep[t]){
			t=i;
		}
	}
	if(dep[t]<n){
		puts("-1");
		return 0;
	}
	num[0]=0;
	num[1]=1;
	num[2]=2;
	ll ans=(1ll<<60),sum;
	int tmp[3];
	for(int k=0;k<6;k++){
		sum=0;
		for(int i=1;i<=n;i++){
			sum+=c[num[i%3]][p[i]];
		}
		if(sum<ans){
			tmp[0]=num[0];
			tmp[1]=num[1];
			tmp[2]=num[2];
		}
		ans=mn(ans,sum);
		next_permutation(num,num+3);
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		a[p[i]]=tmp[i%3];
	}
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]+1);
	}
	puts("");
	return 0;
}