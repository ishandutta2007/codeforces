#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int MN = 1<<20|1;
int n,m,N,S[MN];
LL F[MN],Q[MN];
char ch[MN];
void FWT_xor(LL *f,int op){
	for(int p=2,len=1;len<N;len<<=1,p<<=1)
		for(int i=0;i<N;i+=p)
			for(int k=0;k<len;++k){
				f[i+k]=(f[i+k]+f[i+k+len]);
				f[i+k+len]=(f[i+k]-f[i+k+len]*2ll);
				if(!op)f[i+k]>>=1,f[i+k+len]>>=1;
			}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%s",ch+1);
		for(int j=1;j<=m;++j)
			S[j]|=(1<<i)*(ch[j]=='1');
	}
	N=(1<<n);
	for(int i=1;i<=m;++i){
		Q[S[i]]++;
	}
	for(int i=0;i<N;++i){
		F[i]=F[i>>1]+(i&1);
	}
	for(int i=0;i<N;++i)
		F[i]=min(F[i],n-F[i]);
	FWT_xor(F,1);FWT_xor(Q,1);
	LL ans=n*m;
	for(int i=0;i<N;++i){
		F[i]=F[i]*Q[i];
	}
	FWT_xor(F,0);
	for(int i=0;i<N;++i)
		ans=min(ans,F[i]);
	printf("%lld\n",ans);
	return 0;
}