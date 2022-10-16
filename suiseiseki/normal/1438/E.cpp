#include <cstdio>
typedef long long ll;
const int Maxn=200000;
int n;
int a[Maxn+5];
ll sum[Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=n;i>0;i--){
		int pos=i+2;
		ll tmp_s=a[i+1];
		while(pos<=n&&tmp_s<=(a[i]<<1)){
			if((a[pos]^a[i])==tmp_s){
				ans++;
			}
			tmp_s+=a[pos];
			pos++;
		}
	}
	for(int i=1;i<=n;i++){
		int pos=i-2;
		ll tmp_s=a[i-1];
		while(pos>0&&tmp_s<=(a[i]<<1)){
			if((a[pos]^a[i])==tmp_s&&tmp_s>(a[pos]<<1)){
				ans++;
			}
			tmp_s+=a[pos];
			pos--;
		}
	}
	printf("%d\n",ans);
	return 0;
}