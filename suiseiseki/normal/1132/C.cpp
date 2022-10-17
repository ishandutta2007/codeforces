#include <cstdio>
#define Maxn 5000
struct Segment{
	int left,right;
}a[Maxn+5];
int sum[Maxn+5][3];
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&a[i].left,&a[i].right);
		for(int j=a[i].left;j<=a[i].right;j++){
			sum[j][0]++;
		}
	}
	int now=0;
	for(int i=1;i<=n;i++){
		sum[i][1]=sum[i-1][1];
		sum[i][2]=sum[i-1][2];
		if(sum[i][0]>0){
			now++;
		}
		if(sum[i][0]==1){
			sum[i][1]++;
		}
		if(sum[i][0]==2){
			sum[i][2]++;
		}
	}
	int ans=0;
	for(int i=1;i<=q;i++){
		for(int j=i+1;j<=q;j++){
			ans=mx(ans,now-(sum[a[i].right][1]-sum[a[i].left-1][1])-(sum[a[j].right][1]-sum[a[j].left-1][1])-mx((sum[mn(a[i].right,a[j].right)][2]-sum[mx(a[i].left,a[j].left)-1][2]),0));
		}
	}
	printf("%d\n",ans);
	return 0;
}