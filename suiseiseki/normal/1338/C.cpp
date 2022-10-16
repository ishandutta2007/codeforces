#include <cstdio>
typedef long long ll;
ll n;
int a[12]={0,0,0,1,2,3,2,3,1,3,1,2};
void solve(){
	scanf("%lld",&n);
	n--;
	int id=n%3;
	n=n/3-1;
	ll cur=1,ans=0;
	while(n>=0){
		ans+=cur*a[(n&3)*3+id];
		cur<<=2;
		n=(n>>2)-1;
	}
	printf("%lld\n",ans+cur*(id+1));
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}