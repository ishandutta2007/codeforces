#include <cstdio>
typedef long long ll;
const int Maxn=200000;
int n;
int a[Maxn+5];
int num[20];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=0;j<20;j++){
			num[j]+=(a[i]>>j)&1;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		int val=0;
		for(int j=0;j<20;j++){
			if(num[j]>0){
				val|=(1<<j);
				num[j]--;
			}
		}
		ans+=1ll*val*val;
	}
	printf("%lld\n",ans);
	return 0;
}