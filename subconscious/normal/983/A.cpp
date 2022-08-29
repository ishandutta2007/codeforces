#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const int N=100005;
ll p,q,b;
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		scanf("%lld%lld%lld",&p,&q,&b);
		ll t=__gcd(p,q);
		q/=t;
		while((t=__gcd(q,b))!=1){
			while(q%t==0)q/=t;
		}
		puts(q==1?"Finite":"Infinite");
	}
	//system("pause");
	return 0;
}