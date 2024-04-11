#include<bits/stdc++.h>
const int N=100005,B=320,M=998244353;
using namespace std;
int n,k,ti,a[N],occ[N],pre[N],b[N],f[N],
sum[B],q[B][B<<1|1],now;
inline void mdf(int x,int y){
	b[x]=y;
	int z=x/B;
	if(z==now)return;
	sum[z]=0;
	for(int i=0;i<=B<<1;i++)q[z][i]=0;
	for(int i=z*B+B-1;i>=z*B;i--)
	sum[z]+=b[i],(q[z][sum[z]+B]+=f[i])%=M;
	for(int i=0;i<B<<1;i++)
	(q[z][i+1]+=q[z][i])%=M;
}
int main(){
	//freopen("dat.txt","r",stdin);
	scanf("%d%d",&n,&k);
	memset(occ,-1,N<<2);
	for(int i=0;i<n;i++)
	scanf("%d",a+i),
	pre[i]=occ[a[i]],occ[a[i]]=i;
	f[0]=1;
	for(int i=0;i<n;i++){
		now=(i+1)/B,mdf(i,1);
		if(~pre[i]){
			mdf(pre[i],-1);
			if(~pre[pre[i]])mdf(pre[pre[i]],0);
		}
		ti=0;
		for(int j=i;j/B==now&&~j;j--){
			ti+=b[j];
			if(ti<=k)(f[i+1]+=f[j])%=M;
		}
		for(int j=now-1;~j;j--){
			if(ti<=k+B)(f[i+1]+=q[j][min(B<<1,k+B-ti)])%=M;
			ti+=sum[j];
		}
	}
	printf("%d",f[n]);
}