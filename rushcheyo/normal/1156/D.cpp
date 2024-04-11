#include<cstdio>
int n,fa[2][200005],size[2][200005];

int find(int *fa,int x){return fa[x]==x?x:fa[x]=find(fa,fa[x]);}
void unite(int *fa,int *size,int u,int v){int s=find(fa,u),t=find(fa,v);if(s!=t)fa[s]=t,size[t]+=size[s];}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		fa[0][i]=fa[1][i]=i,size[0][i]=size[1][i]=1;
	for(int i=1,x,y,z;i<n;++i){
		scanf("%d%d%d",&x,&y,&z);
		unite(fa[z],size[z],x,y);
	}
	long long ans=0;
	for(int i=1;i<=n;++i)
		ans+=1LL*size[0][find(fa[0],i)]*size[1][find(fa[1],i)]-1;
	printf("%lld\n",ans);
}