#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=500000;
int n,k;
int c[Maxn+5];
bool cmp(int p,int q){
	return p>q;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	sort(c+1,c+1+n,cmp);
	ll ans=0,sum=0;
	int pos=n+1;
	for(int i=1;i<=n;i++){
		ans+=sum;
		sum+=c[i];
		if(sum<0){
			c[i]=sum;
			pos=i;
			break;
		}
	}
	int num=0,dep=0;
	for(int i=n;i>=pos;i--){
		ans+=1ll*c[i]*dep;
		num++;
		if(num%(k+1)==0){
			dep++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}