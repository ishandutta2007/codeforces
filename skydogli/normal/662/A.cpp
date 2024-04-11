#include<bits/stdc++.h>
using namespace std;
#define MN 200005
#define LL long long
LL p[65];
int n,cnt;
bool Ins(LL x){
	for(int i=60;i>=0&&x;--i)
		if(!p[i]&&((x>>i)&1)){p[i]=x;cnt++;return 1;}
		else if((x>>i)&1)x^=p[i];
	return 0;
}
int main(){
	scanf("%d",&n);
	LL sum=0;
	for(int i=1;i<=n;++i){
		LL a,b;
		scanf("%lld%lld",&a,&b);
		bool rub=Ins(a^b);
		sum^=a;
	}
	if(Ins(sum)) puts("1/1");
	else printf("%lld/%lld",(1ll<<cnt)-1,1ll<<cnt);
	return 0;
}