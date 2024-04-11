#include <cstdio>
#define Maxn 100000
int a[Maxn+5];
struct Segment{
	int num,val;
}seg[Maxn+5];
int mn(int a,int b){
	return a<b?a:b;
}
int mx(int a,int b){
	return a>b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int len=0;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<=n&&a[j]==a[i]){
			j++;
		}
		j--;
		seg[++len].num=j-i+1;
		seg[len].val=a[i];
	}
	int ans=0;
	for(int i=1;i<len;i++){
		ans=mx(ans,mn(seg[i].num,seg[i+1].num)<<1);
	}
	printf("%d\n",ans);
	return 0;
}