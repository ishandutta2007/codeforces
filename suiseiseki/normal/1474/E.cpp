#include <cstdio>
void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
typedef long long ll;
const int Maxn=100000;
int p[Maxn+5];
void solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
	swap(p[1],p[n]);
	ll ans=1ll*(n-1)*(n-1);
	for(int i=2;i<n;i++){
		if(i-1>n-i){
			swap(p[1],p[i]);
			ans+=1ll*(i-1)*(i-1);
		}
		else{
			swap(p[i],p[n]);
			ans+=1ll*(n-i)*(n-i);
		}
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++){
		printf("%d ",p[i]);
	}
	puts("");
	printf("%d\n",n-1);
	for(int i=n-1;i>1;i--){
		if(i-1>n-i){
			printf("%d %d\n",i,1);
		}
		else{
			printf("%d %d\n",i,n);
		}
	}
	printf("%d %d\n",1,n);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}