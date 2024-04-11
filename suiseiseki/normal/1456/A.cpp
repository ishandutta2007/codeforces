#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=200000;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int n,p,k;
int a[Maxn+5];
char s[Maxn+5];
int last[Maxn+5],sum[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	int x,y;
	while(T--){
		scanf("%d%d%d",&n,&p,&k);
		for(int i=0;i<=(n<<1);i++){
			last[i]=sum[i]=0;
		}
		scanf("%s",s+1);
		scanf("%d%d",&x,&y);
		for(int i=1;i<=n;i++){
			a[i]=s[i]-'0';
		}
		for(int i=n;i>0;i--){
			sum[i]=sum[i+k]+a[i];
			last[i]=last[i+k]+1;
		}
		ll ans=Inf;
		for(int i=0;i<=n&&n-i>=p;i++){
			ans=min(ans,1ll*i*y+1ll*x*(last[i+p]-sum[i+p]));
		}
		printf("%lld\n",ans);
	}
	return 0;
}