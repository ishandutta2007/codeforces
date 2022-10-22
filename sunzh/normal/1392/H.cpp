#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int n,m;
const int mod=998244353;
inline int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
} 
int ans;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) ans=(ans+qpow(i,mod-2))%mod;
	ans=1ll*ans*m%mod+1;
	ans=1ll*ans*(1ll*n%mod*qpow(m+1,mod-2)%mod+1)%mod;
	printf("%d\n",ans);
	return 0;
}