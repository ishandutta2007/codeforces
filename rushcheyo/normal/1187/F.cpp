#include<bits/stdc++.h>
using namespace std;

const int N=200005,P=1000000007;
int n,l[N],r[N],p[N],p2[N],ans;

int power(int a,int x)
{
	int ans=1;
	for(;x;x>>=1,a=1LL*a*a%P)if(x&1)ans=1LL*ans*a%P;
	return ans;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",l+i);
	for(int i=1;i<=n;++i)scanf("%d",r+i),p[i]=power(r[i]-l[i]+1,P-2);
	for(int i=1;i+2<=n;++i)
	{
		int x=max({l[i],l[i+1],l[i+2]}),y=min({r[i],r[i+1],r[i+2]});
		if(x<=y)
			ans=(ans+1LL*(y-x+1)*p[i]%P*p[i+1]%P*p[i+2])%P;
	}
	int sum=0;
	for(int i=1;i+1<=n;++i)
	{
		int x=max({l[i],l[i+1]}),y=min({r[i],r[i+1]});
		if(x<=y)
			sum=(sum+(p2[i]=1LL*(y-x+1)*p[i]%P*p[i+1]%P))%P;
	}
	ans=2LL*ans%P;
	for(int i=1;i+1<=n;++i)
		ans=(ans+1LL*p2[i]*(0LL+sum-p2[i]-(i==1?0:p2[i-1])-(i==n-1?0:p2[i+1])))%P;
	ans=(ans+sum)%P;
	int res=(1LL*n*n-2LL*n*sum+ans)%P;
	printf("%d\n",(res+P)%P);
	return 0;
}