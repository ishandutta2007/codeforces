#include <map>
#include <cstdio>
using namespace std;
typedef long long ll;
const int Maxn=200000;
const int Mod=1000000007;
int n;
map<ll,int> mp;
int a[Maxn+5];
ll sum[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i-1];
	}
	mp.clear();
	mp[0]=1;
	int ans=1;
	for(int i=1;i<=n;i++){
		int tmp=(ans-mp[sum[i]]+Mod)%Mod;
		ans=(ans+tmp)%Mod;
		mp[sum[i]]=(mp[sum[i]]+tmp)%Mod;
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}