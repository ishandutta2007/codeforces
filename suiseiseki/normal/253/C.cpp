#include <cstdio>
int mn(int a,int b){
	return a<b?a:b;
}
int mx(int a,int b){
	return a>b?a:b;
}
int ab(int a){
	return a<0?-a:a;
}
int a[105];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int r1,c1,r2,c2;
	scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
	int ans=(1<<30);
	int up,down,now;
	int sum;
	for(int i=1;i<=n;i++){
		up=mn(i,mn(r1,r2));
		down=mx(i,mx(r1,r2));
		now=c1;
		for(int j=up;j<=down;j++){
			now=mn(now,a[j]+1);
		}
		sum=ab(i-r1)+ab(i-r2)+ab(now-c2);
		ans=mn(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}