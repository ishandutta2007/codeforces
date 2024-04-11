#include<iostream>
#include<cstdio>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){ if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
int n;
int a[2000010];
long long f[8000010];
long long maxn;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		a[i]-=i;
	}
	for(int i=1;i<=n;++i){
		f[a[i]+n]=f[a[i]+n]+a[i]+i;
		maxn=max(maxn,f[a[i]+n]);
	} 
	printf("%lld\n",maxn);
	return 0;
}