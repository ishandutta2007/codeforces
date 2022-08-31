#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 100005
using namespace std;
typedef long long ll;
ll k,d,t;
int main(){
	scanf("%lld%lld%lld",&k,&d,&t);
	ll siz=((k-1)/d+1)*d;
	ll rnd=siz+k;
	//k siz-k
	//+2 +1
	t=t*2;
	ll s1=t/rnd;
	ll lef=t-s1*rnd;
	ll s2;
	bool q=0;
	if(lef<=k*2){
		s2=lef/2;
		if(lef&1)q=1;
	}else s2=k+(lef-2*k);
	printf("%lld",s1*siz+s2);
	if(q)printf(".5");
	puts("");
	//system("pause");
}