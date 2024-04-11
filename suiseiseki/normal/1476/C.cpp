#include <cstdio>
template<typename Elem>
Elem abs(Elem a){
	return a<0?-a:a;
}
template<typename Elem>
Elem max(Elem a,Elem b){
	return a>b?a:b;
}
typedef long long ll;
const int Maxn=100000;
int n;
int c[Maxn+5];
int a[Maxn+5],b[Maxn+5];
ll f[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	ll ans=0;
	f[n]=c[n];
	for(int i=n-1;i>0;i--){
		ans=max(ans,f[i+1]+abs(b[i+1]-a[i+1])+1);
		if(a[i+1]==b[i+1]){
			f[i]=c[i];
		}
		else{
			f[i]=max(1ll*c[i],f[i+1]+c[i]-(abs(b[i+1]-a[i+1])-1));
		}
	}
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}