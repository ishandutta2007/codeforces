#include<bits/stdc++.h>
#define N 1048576
using namespace std;
typedef long long ll;
ll a[N],b[N],tp;
int n,m,i,j,k,ans;
inline void fwt(ll*c,bool t){
	for(i=1;i<m;i<<=1)
	for(j=0;j<m;j+=i<<1)
	for(k=0;k<i;k++)
	tp=c[j+k+i],c[j+k+i]=c[j+k]-tp,c[j+k]+=tp,
	t?c[j+k]>>=1,c[j+k+i]>>=1:0;
}
char S[N];
int main(){
	scanf("%d%d",&n,&m);
	for(ans=n*m,i=0;i<n;i++)
	for(scanf("%s",S),j=0;j<m;j++)
	b[j]|=S[j]-'0'<<i;
	for(i=0;i<m;i++)a[b[i]]++,b[i]=0;
	for(m=1<<n,fwt(a,0),i=1;i<m;i++)
	b[i]=b[i>>1]+(i&1);
	for(i=1;i<m;i++)
	b[i]>n-b[i]?b[i]=n-b[i]:0;
	for(fwt(b,0),i=0;i<m;i++)a[i]*=b[i];
	for(fwt(a,1),i=0;i<m;i++)
	ans>a[i]?ans=a[i]:0;
	printf("%d",ans);
}