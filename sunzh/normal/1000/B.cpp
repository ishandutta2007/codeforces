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
int det,ans;
int n,m;
int tim[100010];
int a[100010];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	a[n+1]=m;
	for(int i=n;i>=0;--i){
		if(i&1) tim[i]=tim[i+1];
		else tim[i]=tim[i+1]+a[i+1]-a[i];
	}
	for(int i=1;i<=n;i+=2){
		det=max(m-a[i]-tim[i]-tim[i]-1,det);
	}
	for(int i=2;i<=n;i+=2){
		det=max(m-a[i]-tim[i]-tim[i]+a[i]-a[i-1]-1,det);
	}
	ans=tim[0]+det;
	printf("%d\n",ans);
	return 0;
}