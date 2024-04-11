#include <cstdio>
int father[105];
int jx;
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
	jx--;
	father[fa_y]=fa_x;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	if(n!=m){
		puts("NO");
		return 0;
	}
	jx=n;
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
	int x,y;
	while(m--){
		scanf("%d%d",&x,&y);
		merge(x,y);
	}
	if(jx==1){
		puts("FHTAGN!");
	}
	else{
		puts("NO");
	}
	return 0;
}