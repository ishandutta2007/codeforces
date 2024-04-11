#include<bits/stdc++.h>
using namespace std;
#define MN 200005
#define LL long long
LL gcd(LL a,LL b){if(!b)return a;return gcd(b,a%b);}
int t;
bool vis[26];
char ch[MN],T[MN],S[MN];
int nex[MN][26];
LL phi(LL a){
	LL ans=a;
	for(LL i=2;i*i<=a;++i){
		if(a%i==0){
			ans=ans/i*(i-1);
			while(a%i==0)a/=i;
		}
	}
	if(a!=1)ans=ans/a*(a-1);
	return ans;
}
int main(){
	scanf("%d",&t);
	while(t--){
		LL a,m;
		scanf("%lld%lld",&a,&m);
		LL qwq=gcd(a,m);m/=qwq;
		printf("%lld\n",phi(m));
	}
}