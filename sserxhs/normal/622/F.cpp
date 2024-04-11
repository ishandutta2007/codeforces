#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+2,p=1e9+7;
int ss[N],a[N],w[N];
int n,m,i,j,k,ans,gs;
inline int ksm(register int x,register int y)
{
	register int r=1;
	while (y)
	{
		if (y&1) r=(ll)r*x%p;
		x=(ll)x*x%p;
		y>>=1;
	}
	return r;
}
inline int f(register int *a,register int n,register int m)//0nm-1
{
	static int inv[N],l[N],r[N],ifac[N]; 
	ifac[0]=inv[1]=1;
	for (i=2;i<=m;i++) inv[i]=p-(ll)p/i*inv[p%i]%p;
	for (i=1;i<=m;i++) ifac[i]=(ll)ifac[i-1]*inv[i]%p;//
	register int ans=0,rr=0;
	l[0]=n;r[m+1]=1;
	for (i=1;i<m;i++) l[i]=(ll)l[i-1]*(n-i)%p;
	for (i=m;i;i--) r[i]=(ll)r[i+1]*(n-i)%p;
	//if (m&1) rr=p-a[0]; else rr=a[0];
	//ans=(ll)rr*ifac[m]%p*r[1]%p;
	for (i=1;i<=m;i++)
	{
		if ((m^i)&1) rr=p-a[i]; else rr=a[i];
		ans=(ans+(ll)rr*ifac[i]%p*ifac[m-i]%p*l[i-1]%p*r[i+1])%p;
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);m+=2;
	a[1]=1;
	for (i=2;i<=m;i++)
	{
		if (!a[i]) a[ss[++gs]=i]=ksm(i,m-2);
		for (j=1;j<=gs&&ss[j]*i<=m;j++)
		{
			a[i*ss[j]]=(ll)a[i]*a[ss[j]]%p;
			if (i%ss[j]==0) break;
		}
	}
	for (i=2;i<=m;i++)
	{
		a[i]+=a[i-1];
		if (a[i]>=p) a[i]-=p;
	}
	if (n<=m)
	{
		printf("%d",a[n]);return 0;
	}a[0]=114514;
	printf("%d",f(a,n,m));
}