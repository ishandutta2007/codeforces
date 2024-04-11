#include <cstdio>
int a[105];
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int maxn=0;
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxn=mx(maxn,a[i]);
	}
	int now=m;
	for(int i=1;i<=n;i++){
		now-=maxn-a[i];
		a[i]=maxn;
	}
	if(now<=0){
		printf("%d %d\n",maxn,maxn+m);
	}
	else{
		printf("%d %d\n",maxn+(now+n-1)/n,maxn+m);
	}
	return 0;
}