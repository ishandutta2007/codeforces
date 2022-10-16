#include <cstdio>
typedef long long ll;
const int Maxn=100000;
int n;
int a[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==3){
		if(a[2]&1){
			puts("-1");
		}
		else{
			printf("%d\n",a[2]/2);
		}
		return;
	}
	bool flag=1;
	for(int i=2;i<n;i++){
		flag&=(a[i]==1);
	}
	if(flag){
		puts("-1");
		return;
	}
	ll ans=0,sum=0;
	for(int i=2;i<n;i++){
		ans+=(a[i]&1);
		sum+=a[i];
	}
	printf("%lld\n",(sum+ans)/2);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}