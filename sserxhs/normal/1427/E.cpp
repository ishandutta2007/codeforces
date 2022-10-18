#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+2,M=1e6+2;
ll m;
ll ans[N][3],phi[M],ss[M];
ll n,c,fh,i,j,t,q,gs,x,y,z;
bool ed[M];
inline void read(ll &x)
{
	c=getchar();fh=1;
	while ((c<48)||(c>57))
	{
		if (c=='-') {c=getchar();fh=-1;break;}
		c=getchar();
	}
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	x*=fh;
}
inline ll ksm(register ll x,register ll y,const ll p)
{
	register ll r=1;
	while (y)
	{
		if (y&1) r=(ll)r*x%p;
		x=(ll)x*x%p;y>>=1;
	}
	return r;
}
int main()
{
	read(n);m=n;phi[1]=1;
	for (i=2;i<=n;i++)
	{
		if (!ed[i]) phi[ss[++gs]=i]=i-1;
		for (j=1;(j<=gs)&&(i*ss[j]<=n);j++)
		{
			ed[i*ss[j]]=1;
			if (i%ss[j]==0)
			{
				phi[i*ss[j]]=phi[i]*ss[j];break;
			}
			phi[i*ss[j]]=phi[i]*(ss[j]-1);
		}
	}
	for (i=1;i<=n;i<<=1);i>>=2;
	while (i)
	{
		ans[++q][1]=m;ans[q][2]=m;ans[q][0]=0;
		m<<=1;i>>=1;
	}
	ans[++q][1]=m;ans[q][2]=n;ans[q][0]=1;m^=n;//printf("m=%lld\n",m);
	x=ksm(m%n,phi[n]-1,n);if (1^x*m&1) x+=n;y=0;//printf("x=%lld\n",x);
	while (x)
	{
		if (x&1) {if (y){ans[++q][1]=m;ans[q][2]=y;y+=m;} else y=m;}
		x>>=1;if (x){ans[++q][1]=m;ans[q][2]=m;m<<=1;}
	}//printf("y=%lld\n",y);
	if (y%n!=1) while (1);
	if (y!=1){
	x=(y-1)/n;z=y;y=0;
	while (x)
	{
		if (x&1) {if (y){ans[++q][1]=n;ans[q][2]=y;y+=n;} else y=n;}
		x>>=1;if (x){ans[++q][1]=n;ans[q][2]=n;n<<=1;}
	}x=z-1;
	ans[++q][1]=x;ans[q][2]=x+1;ans[q][0]=1;}
	printf("%lld\n",q);
	for (i=1;i<=q;i++) printf("%lld %c %lld\n",ans[i][1],ans[i][0]?'^':'+',ans[i][2]);
}