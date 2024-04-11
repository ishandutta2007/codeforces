#include <cmath>
#include <cstdio>
#include <cstring>
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=100000;
int n,block;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int a[Maxn+5];
int lim[Maxn+5],lim_len,father[Maxn+5];
int f[Maxn+5];
void init_dfs(int u,int fa){
	lim[++lim_len]=u;
	father[u]=fa;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		init_dfs(v,u);
	}
}
int calc(int k){
	if(a[k]!=-1){
		return a[k];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		f[i]=1;
	}
	for(int i=lim_len;i>1;i--){
		int u=lim[i];
		if(f[u]+f[father[u]]>=k){
			f[father[u]]=f[u]=-1;
			ans++;
		}
		else if(f[father[u]]!=-1){
			f[father[u]]=max(f[father[u]],f[u]+1);
		}
	}
	return a[k]=ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	memset(a,-1,sizeof a);
	block=(int)sqrt(n*log2(n));
	init_dfs(1,0);
	a[1]=n;
	for(int i=2;i<=block;i++){
		calc(i);
	}
	for(int i=block+1,j;i<=n;i=j+1){
		calc(i);
		int left=i,right=n,mid;
		while(left<right){
			mid=(left+right+1)>>1;
			if(calc(mid)!=a[i]){
				right=mid-1;
			}
			else{
				left=mid;
			}
		}
		j=left;
		for(int k=i+1;k<=j;k++){
			a[k]=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}