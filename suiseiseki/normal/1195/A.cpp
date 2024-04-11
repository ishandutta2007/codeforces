#include <cstdio>
int a[1005];
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		a[x]++;
	}
	int ans=0;
	n=((n+1)>>1);
	int now;
	for(int i=1;i<=k&&n>0;i++){
		ans+=mn(n<<1,((a[i]>>1)<<1));
		now=a[i];
		a[i]-=mn(n<<1,((a[i]>>1)<<1));
		n-=(mn(n<<1,((now>>1)<<1))>>1);
	}
	if(n>0){
		for(int i=1;i<=k&&n>0;i++){
			if(a[i]>0){
				a[i]--;
				n--;
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}