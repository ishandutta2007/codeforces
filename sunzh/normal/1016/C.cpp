#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
int inline read(){
	int num=0,neg=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
	while(isdigit(c)){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	return num*neg;
}
int n;
long long a[300010][2];
int dfn=-1;
long long ans,cnt;
long long s1[300010],s2[300010],s[300010];//s1 shang-xia  s2 xia-shang  s sum
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i][0]=read();
	for(int i=1;i<=n;++i) a[i][1]=read();
	for(int i=n;i>=1;--i){
		s[i]=s[i+1]+a[i][0]+a[i][1];
		s1[i]=s1[i+1]+s[i+1]+a[i][0]+(a[i][1]*(n-i+1)<<1ll);
		s2[i]=s2[i+1]+s[i+1]+a[i][1]+(a[i][0]*(n-i+1)<<1ll);
	}
	for(int i=0;i<=n;++i){
		if(i&1){ans=max(ans,cnt+s2[i+1]+s[i+1]*dfn); cnt=cnt+a[i+1][1]*(dfn+1)+a[i+1][0]*(dfn+2); ++dfn;++dfn;}
		else {ans=max(ans,cnt+s1[i+1]+s[i+1]*dfn); cnt=cnt+a[i+1][0]*(dfn+1)+a[i+1][1]*(dfn+2); ++dfn;++dfn;}
	}
	printf("%lld\n",ans);
	return 0;
}