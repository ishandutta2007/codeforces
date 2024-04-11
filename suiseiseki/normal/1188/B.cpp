#include <map>
#include <cstdio>
using namespace std;
#define ll long long
int n,k,p,i,x;
map<int,int> mp;
ll ans;
int main(){
	for(scanf("%d%d%d",&n,&p,&k),i=1;i<=n;i++){
		scanf("%d",&x);
		x=((1LL*x*x%p*x%p*x%p-1LL*k*x%p)%p+p)%p;
		ans+=mp[x];
		mp[x]++;
	}
	printf("%lld\n",ans);
	return 0;
}