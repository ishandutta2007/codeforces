#include <cstdio>
#include <algorithm>
using namespace std;
int min(int a,int b){
	return a<b?a:b;
}
typedef long long ll;
const int Maxn=300000;
int a[3][Maxn+5];
int n[3];
int minn[3];
ll s[3];
int main(){
	for(int i=0;i<3;i++){
		scanf("%d",&n[i]);
	}
	ll sum=0;
	for(int i=0;i<3;i++){
		for(int j=1;j<=n[i];j++){
			scanf("%d",&a[i][j]);
			sum+=a[i][j];
			s[i]+=a[i][j];
		}
		minn[i]=a[i][1];
		for(int j=2;j<=n[i];j++){
			minn[i]=min(minn[i],a[i][j]);
		}
	}
	ll ans=0;
	for(int i=0;i<3;i++){
		ans=max(ans,sum-(s[i]<<1));
	}
	sort(minn,minn+3);
	ans=max(ans,sum-(minn[0]<<1)-(minn[1]<<1));
	printf("%lld\n",ans);
	return 0;
}