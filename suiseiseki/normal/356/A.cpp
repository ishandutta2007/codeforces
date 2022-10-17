#include <cstdio>
#define Maxn 300000
int father[Maxn+5];
int find(int x){
	if(x==father[x]){
		return x;
	}
	return father[x]=find(father[x]);
}
void merge(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	if(fa_x==fa_y){
		return;
	}
	father[fa_x]=fa_y;
}
int a[Maxn+5];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
	father[n+1]=n+1;
	int x,y,w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&w);
		for(int j=find(x);j<=y;j=find(j+1)){
			if(j==w){
				continue;
			}
			a[j]=w;
			merge(j,j+1);
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	puts("");
	return 0;
}