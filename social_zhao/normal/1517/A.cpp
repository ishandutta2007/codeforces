#include<cstdio>
#define ll long long
using namespace std;
inline ll read(){
	char c=getchar();ll x=0,f=1;
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=0;
	for(;c<='9'&&c>='0';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return f?x:-x;
}
int main(){
	int T=read();
	while(T--){
		ll n=read();
		if(n%2050!=0){
			printf("-1\n");continue;
		}
		else n/=2050;
		int ans=0;
		while(n){
			ans+=n%10,n/=10;
		}
		printf("%d\n",ans);
	}
	return 0;
}