#include <cstdio>
#include <algorithm>
const int Maxn=1000;
int n,d;
int lis[Maxn+5];
int len;
namespace DSU{
	int fa[Maxn+5],sz[Maxn+5];
	void init(){
		for(int i=1;i<=n;i++){
			fa[i]=i,sz[i]=1;
		}
	}
	int find(int x){
		if(x==fa[x]){
			return x;
		}
		return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		int fa_x=find(x),fa_y=find(y);
		if(fa_x==fa_y){
			return;
		}
		fa[fa_y]=fa_x;
		sz[fa_x]+=sz[fa_y];
	}
}
int main(){
	scanf("%d%d",&n,&d);
	DSU::init();
	int num_free=0;
	for(int i=1;i<=d;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(DSU::find(x)==DSU::find(y)){
			num_free++;
		}
		else{
			DSU::merge(x,y);
		}
		len=0;
		for(int j=1;j<=n;j++){
			if(DSU::find(j)==j){
				lis[++len]=DSU::sz[j];
			}
		}
		std::nth_element(lis+1,lis+1+std::min(num_free,len),lis+1+len,[&](int p,int q){return p>q;});
		int sum=0;
		for(int j=1;j<=std::min(num_free+1,len);j++){
			sum+=lis[j];
		}
		printf("%d\n",sum-1);
	}
	return 0;
}