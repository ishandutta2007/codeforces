#include<stdio.h>
#include<cstring>
#include<algorithm>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
using namespace std;
const int N=21;
double f[1<<20];
int sz[1<<20];
double sum[1<<20];
int n,k;double p[N];
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%lf",&p[i]);
	int S=0;
	rep(i,1,n)if(p[i]>0)S|=(1<<(i-1));
	rep(i,0,(1<<n)-1){
		sz[i]=sz[i>>1]+(i&1);
		rep(j,0,n-1)if((1<<j)&i)sum[i]+=p[j+1];
	}
	k=min(k,sz[S]);
	f[0]=1;
	rep(i,0,(1<<n)-1)if(f[i]>1e-13){
		rep(j,0,n-1)if(!(i&(1<<j)))if(p[j+1]!=0)
		f[i+(1<<j)]+=f[i]*p[j+1]*(1./(1-sum[i]));
	}
	rep(i,1,n){
		double ans=0;
		for(int j=0;j<(1<<n);j++)if(sz[j]==k)if(j&(1<<(i-1)))ans+=f[j];
		printf("%.10lf ",ans);
	}
	return 0;
}