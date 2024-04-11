#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M
using namespace std;
LL read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL n,m,p[1000200],ans;
LL sq(LL x){return x*x;}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(LL i=1;i<=n;i++) p[i]=read();
	sort(p+1,p+n+1);
	for(int i=1;i<=(n>>1);i++) ans+=sq(p[i]+p[n+1-i]);
	printf("%lld\n",ans); return 0;
}