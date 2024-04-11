#include<stdio.h>
int f[10001];
int n,m;
int getfa(int x){
	if(f[x]==x) return x;
	return f[x]=getfa(f[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) f[i]=i;
	int ans=n;
	for(int i=1;i<=n;++i){
		int x,y;
		scanf("%d",&x);
		x=getfa(x),y=getfa(i);
		if(x!=y) --ans,f[x]=y;
	}
	printf("%d\n",ans);
	return 0;
}