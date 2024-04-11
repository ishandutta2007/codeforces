#include <cstdio>
int t[100005],l[100005];
int main(){
	int n,L,m;
	scanf("%d%d%d",&n,&L,&m);
	if(n==0){
		printf("%d\n",L/m);
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d%d",&t[i],&l[i]);
	}
	int ans=0;
	t[n+1]=L;
	for(int i=0;i<=n;i++){
		ans+=(t[i+1]-(t[i]+l[i]))/m;
	}
	printf("%d\n",ans);
	return 0;
}
//////////