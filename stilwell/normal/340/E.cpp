#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,q,i,j,k;
int a[2000005];
long long fac[2000005],p,ans,tmp;
long long Div[2000005],fac_div[2000005];

long long C(int n,int m){return fac[n]*fac_div[m]%p*fac_div[n-m]%p;}

void read(int &x)
{
	char ch;bool f=false;
	for(ch=getchar();(ch!='-')&&(ch<'0'||ch>'9');)ch=getchar();
	if(ch=='-')f=true,ch=getchar();
	for(x=0;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

int main()
{
	p=1000000007;
	scanf("%d",&n);
	for(i=1;i<=n;++i)read(a[i]);
	for(i=1;i<=n;++i)
	if(a[i]==i)
	{
		printf("0\n");
		return 0;
	}
	fac[0]=1;
	for(i=1;i<=n;++i)fac[i]=fac[i-1]*i%p;
	Div[1]=1;
	for(i=2;i<=n;++i)Div[i]=Div[p%i]*(p-p/i)%p;
	fac_div[0]=1;
	for(i=1;i<=n;++i)fac_div[i]=fac_div[i-1]*Div[i]%p;
	for(i=1;i<=n;++i)
	if(a[i]!=-1)
	{
		++q;
		if(a[a[i]]==-1)++m;
	}
	m=n-q-m;
	for(i=0;i<=m;++i)
	{
		tmp=C(m,i)*fac[n-q-i]%p;
		if(i%2)ans=(ans+p-tmp)%p;
		else ans=(ans+tmp)%p;
	}
	printf("%I64d\n",ans);
}