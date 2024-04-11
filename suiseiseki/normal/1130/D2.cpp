#include <cstdio>
#define Maxn 5000
int len[Maxn+5];
int num[Maxn+5];
int n,m;
int dist(int x,int y){
	return (y-x+n)%n;
}
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	scanf("%d%d",&n,&m);
	int a,b;
	int tmp=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		if(!num[a]){
			num[a]=b;
		}
		else{
			len[a]++;
			if(dist(a,b)<dist(a,num[a])){
				num[a]=b;
			}
			if(len[a]>len[tmp]){
				tmp=a;
			}
		}
	}
	int ans;
	for(int i=1;i<=n;i++){
		ans=0;
		for(int j=1;j<=n;j++){
			if(num[j]){
				ans=mx(ans,dist(i,j)+len[j]*n+dist(j,num[j]));
			}
		}
		printf("%d ",ans);
	}
	puts("");
	return 0;
}