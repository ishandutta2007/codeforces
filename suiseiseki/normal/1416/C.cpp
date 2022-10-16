#include <cstdio>
typedef long long ll;
const int Maxn=300000;
int n;
int a[Maxn+5];
int d[Maxn+5];
int x;
ll ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int k=29;k>=0;k--){
		ll num_0=0,num_1=0;
		for(int i=1,j;i<=n;i=j+1){
			j=i;
			while(j<=n&&(a[j]^a[i])<(1<<(k+1))){
				j++;
			}
			j--;
			ll sum_0=0,sum_1=0;
			for(int l=i;l<=j;l++){
				if((a[l]>>k)&1){
					sum_1++;
					num_1+=sum_0;
				}
				else{
					sum_0++;
					num_0+=sum_1;
				}
			}
			int tmp=i-1;
			for(int l=i;l<=j;l++){
				if((a[l]>>k)&1){
					d[++tmp]=a[l];
				}
			}
			for(int l=i;l<=j;l++){
				if(!((a[l]>>k)&1)){
					d[++tmp]=a[l];
				}
			}
			for(int l=i;l<=j;l++){
				a[l]=d[l];
			}
		}
		if(num_0<=num_1){
			ans+=num_0;
		}
		else{
			ans+=num_1;
			x|=(1<<k);
		}
	}
	printf("%lld %d\n",ans,x);
	return 0;
}