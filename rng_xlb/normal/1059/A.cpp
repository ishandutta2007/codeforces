#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 100020
using namespace std;
LL read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL n,A[M],B[M],len,x,ans;
int main(){
	n=read(),len=read(),x=read();
	for(LL i=1;i<=n;i++) A[i]=read(),B[i]=A[i]+read();
	A[0]=B[0]=0;
	for(LL i=0;i<n;i++) ans+=(A[i+1]-B[i])/x;
	ans+=(len-B[n])/x,printf("%lld\n",ans);
}