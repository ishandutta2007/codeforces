#include<bits/stdc++.h>
const int N=131072,M=1000000007,I=M+1>>1;
typedef long long ll;
using namespace std;
int n,i,j,k,p[N];
ll a[18][N],b[18][N],s[N],d[N],f[N],tp;
inline void fwt(ll*c,int t){
	for(i=1;i<N;i<<=1)
	for(j=0;j<N;j+=i<<1)
	for(k=0;k<i;k++)
	if(t&4)tp=c[j+k+i],c[j+k+i]=(c[j+k]-tp)%M,(c[j+k]+=tp)%=M,
	t&1?c[j+k]=I*c[j+k]%M,c[j+k+i]=I*c[j+k+i]%M:0;
	else if(t&2)(c[j+k]+=(t&1?-c[j+k+i]:c[j+k+i]))%=M;
	else (c[j+k+i]+=(t&1?-c[j+k]:c[j+k]))%=M;
}
int main(){
	scanf("%d",&n);
	for(;n--;)
	scanf("%d",&k),s[k]++,d[k]++;
	for(f[1]=p[1]=1,i=2;i<N;i++)
	f[i]=(f[i-1]+f[i-2])%M,p[i]=p[i>>1]+(i&1);
	for(i=0,n=18;i<N;i++)a[p[i]][i]=s[i];
	for(int l=0;l<n;l++)fwt(a[l],0);
	for(i=0;i<N;i++)
	for(j=0;j<n;j++)for(k=0;j+k<n;k++)
	(b[j+k][i]+=a[j][i]*a[k][i])%=M;
	for(int l=0;l<n;l++)fwt(b[l],1);
	for(fwt(d,4),i=0;i<N;i++)(d[i]*=d[i])%=M;
	for(fwt(d,5),i=0;i<N;i++)
	(d[i]*=f[i])%=M,(s[i]*=f[i])%=M;
	for(fwt(d,2),fwt(s,2),i=0;i<N;i++)
	(d[i]*=s[i])%=M,s[i]=f[i]*b[p[i]][i]%M;
	for(fwt(s,2),i=0;i<N;i++)(d[i]*=s[i])%=M;
	for(fwt(d,3),tp=0,i=1;i<N;i<<=1)tp+=d[i];
	printf("%d",(tp%M+M)%M);
}