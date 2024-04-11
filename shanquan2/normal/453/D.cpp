#include<cstdio>
using namespace std;

long long x[1048577],y[1048577],c[1048577],z[1048577],m,t,p;
long long b[21];
void build(long long *q,long long l,long long r){
	if(l==r)return;
	long long mid=(l+r)>>1;
	build(q,l,mid);build(q,mid+1,r);
	for(int i=l;i<=r;i++) c[i]=(i>mid)?q[i-mid-1+l]-q[i]:q[i+mid+1-l]+q[i];
	for(int i=l;i<=r;i++) q[i]=c[i]%p;
	return;
}
void built(long long *q,long long l,long long r){
	if(l==r)return;
	long long mid=(l+r)>>1;
	for(int i=l;i<=r;i++) c[i]=(i>mid)?q[i-mid-1+l]-q[i]:q[i+mid+1-l]+q[i];
	for(int i=l;i<=r;i++) q[i]=c[i]%p;
	built(q,l,mid);built(q,mid+1,r);
	return;
}
/*long long mul(int x,int y){
	long long tmp=x,ans=0;
	while(y>0){
		if(y&1)
			ans+=tmp,ans%=p;
		y/=2;tmp*=2;tmp%=p;
	}
	return ans;
}*/
inline long long mul(long long a, long long b){return ((a*b-(long long)(((long double)a)/p*b+1e-3)*p)%p+p)%p;}
long long pow(long long a, long long b)
{
	long long ans = 1;
	while (b)
	{
		if (b&1)	ans = mul(ans,a);
		a = mul(a,a), b >>= 1;
	}
	return ans;
}
int main(){
	scanf("%I64d%I64d%I64d",&m,&t,&p);
//	printf("%I64d\n",mul(1073741824,1073741824));
	int n=1<<m;p*=n;
	for(int i=0;i<n;i++)
		scanf("%I64d",&x[i]);
	for(int i=0;i<=m;i++)
		scanf("%I64d",&b[i]);
	for(int i=0;i<n;i++){
		int t=0;
		for(int j=0;j<m;j++)if(i&(1<<j))t++;
		y[i]=b[t];
	}
	build(x,0,n-1);
	build(y,0,n-1);
	for(int i=0;i<n;i++)y[i]=(y[i]+p)%p,y[i]=pow(y[i],t);
	for(int i=0;i<n;i++)z[i]=mul(x[i],y[i]);
	built(z,0,n-1);
	for(int i=0;i<n;i++)printf("%I64d\n",((z[i]+p)%p)/n);
	return 0;
}