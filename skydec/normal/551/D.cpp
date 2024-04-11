#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
unsigned long long n,k;int l,m;
int Pow(int a,unsigned long long b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%m)if(b&1)c=c*1ll*a%m;
	return c;
}
struct mat{
	int c[2][2];
};
inline mat operator *(const mat &a,const mat &b){
	mat c;memset(c.c,0,sizeof c.c);
	rep(k,0,1)rep(i,0,1)rep(j,0,1)
	c.c[i][j]=(c.c[i][j]+a.c[i][k]*1ll*b.c[k][j])%m;
	return c;
}
int Main(){
	mat dw;
	dw.c[0][0]=0;
	dw.c[0][1]=dw.c[1][1]=dw.c[1][0]=1;
	mat cs;
	cs.c[0][0]=cs.c[0][1]=1;
	cs.c[1][0]=cs.c[1][1]=0;
	LL b=n;
	for(;b;b>>=1,dw=dw*dw)if(b&1)cs=cs*dw;
	return cs.c[0][1];
}
int main(){
	scanf("%I64u%I64u%d%d",&n,&k,&l,&m);
	if(l==0){
		printf("%d\n",(k==0)%m);
		return 0;
	}
	if(l<63){
		if(k>=(1ll<<l)){
			printf("0\n");
			return 0;
		}
	}
	
	int ans=1;
	int gt=Main();
	per(i,l-1,0){
		if(!((k>>i)&1))ans=ans*1ll*gt%m;
		else ans=ans*1ll*(Pow(2,n)-gt)%m;
	}
	printf("%d\n",(ans+m)%m);
	return 0;
}