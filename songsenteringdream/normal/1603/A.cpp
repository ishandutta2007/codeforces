#include<cstdio>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int o=1e5+10,inf=1e9+10;
int T,n,a[o];long long lcm=1;
inline bool chk(){
	for(int i=1;i<=n;++i){if(lcm<inf) lcm=lcm*(i+1)/gcd(lcm,i+1);if(a[i]%lcm==0) return false;}
	return true;
}
int main(){
	for(scanf("%d",&T);T--;lcm=1){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		printf(chk()?"YES\n":"NO\n");
	}
	return 0;
}