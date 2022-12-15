#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 200020
using namespace std;
int read(){
	int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,on,up,down;
const long double eps=1e-6;
const long double iv=0.5;
long double l,r,X[M],Y[M],ans;
bool check(long double x){
	long double maxn=1e16,minn=-1e16;
//	minn*=maxn,maxn*=maxn; 
	for(int i=1;i<=n;i++){
		long double len=sqrtl(x*x-(x-Y[i])*(x-Y[i]));
//		printf("%.5Lf\n",len);
		minn=max(minn,X[i]-len),maxn=min(maxn,X[i]+len);
	}
//	printf("%.5Lf  %.5Lf       %.5Lf\n",minn,maxn,x*x);
	return minn<=maxn;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		cin>>X[i]>>Y[i];
		if(Y[i]<0.0) down++;
		else if(Y[i]>0.0) up++;
	}
	if(up*down>0){puts("-1");return 0;}
	if(down){for(int i=1;i<=n;i++) Y[i]*=-1.0;}
	for(int i=1;i<=n;i++) l=max(l,Y[i]*iv); r=1e16;
	for(int i=1;i<=120;i++){
		long double md=(l+r)/2;
		if(check(md)) r=md-eps,ans=md;
		else l=md+eps;
	}
	printf("%.10lf\n",(double)ans);
	return 0;
}