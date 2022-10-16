#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=1000000;
typedef long long ll;
int n,k;
bool np[Maxn+5];
int p[Maxn+5],p_len,phi[Maxn+5];
void init(){
	np[0]=np[1]=1;
	for(int i=2;i<=Maxn;i++){
		if(!np[i]){
			p[++p_len]=i;
			phi[i]=i-1;
		}
		for(int j=1,x;j<=p_len&&(x=i*p[j])<=Maxn;j++){
			np[x]=1;
			if(i%p[j]==0){
				phi[x]=phi[i]*p[j];
				break;
			}
			phi[x]=phi[i]*(p[j]-1);
		}
	}
}
int a[Maxn+5],len;
int main(){
	init();
	scanf("%d%d",&n,&k);
	if(k==1){
		puts("3");
		return 0;
	}
	for(int i=3;i<=n;i++){
		a[++len]=phi[i];
	}
	sort(a+1,a+1+len);
	ll ans=0;
	for(int i=1;i<=k;i++){
		ans+=a[i];
	}
	printf("%lld\n",ans+2);
	return 0;
}