#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k,Max,tot,L,R;
int a[1000005],h[1000005];
int l[1000005],nl[1000005];
int r[1000005];
long long ans;

char ch;
void read(int &x)
{
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
	for(x=0;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		read(a[i]);
		if(a[i]>Max)Max=a[i];
	}
	for(k=1;k<=n;++k)if(a[k]==Max)break;
	for(i=k;i<=n;++i)h[++tot]=a[i];
	for(i=1;i<k;++i)h[++tot]=a[i];
	h[++tot]=Max;
	tot=0;
	for(i=1;i<=n;++i)if(a[i]==Max)++tot;
	ans=(long long)tot*(tot-1)/2;
	for(L=1;L<=n;)
	{
		for(R=L+1;h[R]<Max;++R);
		if(L+1!=R)
		{
			for(i=L+1;i<R;++i)
			{
				for(j=i-1;h[j]<h[i];j=l[j]);
				if(h[j]==h[i])nl[i]=nl[j]+1,ans+=nl[i];
				l[i]=j;
			}
			for(i=L+1;i<R;++i)l[i]=0;
			for(i=L+1;i<R;++i)
			{
				for(j=i-1;h[j]<=h[i];j=l[j]);
				l[i]=j;
			}
			for(i=R-1;i>L;--i)
			{
				for(j=i+1;h[j]<=h[i];j=r[j]);
				r[i]=j;
			}
			for(i=L+1;i<R;++i)
			if(l[i]==L&&r[i]==R)
			{
				if(L==1&&R==n+1)++ans;
				else ans+=2;
			}else ans+=2;
		}
		L=R;
	}
	printf("%I64d\n",ans);
}