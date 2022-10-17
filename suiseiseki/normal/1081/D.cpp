#include <cstdio>
#define Maxn 100000
int f[Maxn+5];
int num[Maxn+5];
int a[Maxn+5];
struct Edge{
	int from,to;
	int value;
}edge[Maxn+5];
int n,m,k;
void init(){
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=n;i++){
		num[i]=a[i];
	}
}
int find(int x){
	if(x==f[x]){
		return x;
	}
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	if(fa_x==fa_y){
		return;
	}
	f[fa_x]=fa_y;
	num[fa_y]+=num[fa_x];
}
int start;
bool check(int x){
	init();
	for(int i=1;i<=m;i++){
		if(edge[i].value<=x){
			merge(edge[i].from,edge[i].to);
		}
	}
	if(num[find(start)]==k){
		return 1;
	}
	return 0;
}
int main(){
	int x;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&x);
		a[x]=1;
		start=x;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].value);
	}
	int left=1,right=1000000000,mid;
	while(left<right){
		mid=(left+right)>>1;
		if(check(mid)){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	for(int i=1;i<=k;i++){
		printf("%d ",left);
	}
	puts("");
	return 0;
}