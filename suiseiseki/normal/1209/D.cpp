#include <cstdio>
int n,k,fa[1<<18],ans;
int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(getf(x)!=getf(y)){
			fa[fa[x]]=fa[y];
		}
		else{
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}