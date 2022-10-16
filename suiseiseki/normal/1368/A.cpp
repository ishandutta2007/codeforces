#include <cstdio>
void solve(){
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	int ans=0;
	while(a<=n&&b<=n){
		if(a>b){
			b+=a;
		}
		else{
			a+=b;
		}
		ans++;
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