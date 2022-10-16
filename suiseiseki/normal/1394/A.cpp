#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=100000;
typedef long long ll;
int d,n,m;
int a[Maxn+5];
ll sum_1[Maxn+5],sum_2[Maxn+5];
int main(){
	scanf("%d%d%d",&n,&d,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int num=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=m){
			num++;
		}
	}
	for(int i=num;i>0;i--){
		sum_1[i]=sum_1[i+1]+a[i];
	}
	for(int i=n;i>num;i--){
		sum_2[i]=sum_2[i+1]+a[i];
	}
	ll ans=0;
	d++;
	for(int i=0;i<=num;i++){
		ans=max(ans,sum_1[num-i+1]+sum_2[n-((n-i+d-1)/d)+1]);
	}
	printf("%lld\n",ans);
	return 0;
}