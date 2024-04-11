#include <cstdio>
typedef long long ll;
const int Maxn=100000;
int n;
bool vis[Maxn+5];
int q[Maxn+5],p[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	for(int i=1;i<=n;i++){
		int p;
		scanf("%d",&p);
		q[p]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		p[i]=q[p[i]];
	}
	int num_n=0,num_0=0,num_p=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		int len=0;
		for(int j=i;!vis[j];j=p[j]){
			vis[j]=1,len++;
		}
		num_n+=len/2,num_p+=len/2;
		if(len&1){
			num_0++;
		}
	}
	ll ans=0;
	for(int i=1;i<=num_n;i++){
		ans-=i;
	}
	for(int i=n;i>=n-num_p+1;i--){
		ans+=i;
	}
	printf("%lld\n",ans*2);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}