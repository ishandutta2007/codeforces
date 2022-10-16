#include <stdio.h>
#include <string.h> 
#include <algorithm>
#include <math.h>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
int a[100005];//,f[100005][2],r[100005][2];
signed main()
{
	int n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int ansl=0,ansr=0,mx=0,eq=0,pos=0;
	for(int i=2;i<=n-1;i++)
	{
		if(a[i]>a[i-1]&&a[i]>a[i+1])
		{
			int l=i-1,r=i+1;
			while(a[l-1]<a[l]&&l>1)l--;
			while(a[r+1]<a[r]&&r<n)r++;
			int p=i-l+1>r-i+1?i-l+1:r-i+1;
			//printf("(%lld %lld %lld)\n",i-l+1,r-i+1,p);
			if(p>mx)
			{
				eq=0;
				ansl=i-l+1;
				ansr=r-i+1;
				mx=p;
				pos=i;
			}
			else if(p==mx)
			{
				eq=1;
			}
		}
	}
	if(ansl==ansr&&!eq&&n>2&&ansl>1&&ansl%2)
	{
		int R=pos+ansr-1,L=pos-ansl+1;
		int cntR=0,cntL=0;
		while(a[R+cntR]<a[R+cntR+1]&&R+cntR<n)cntR++;
		while(a[L-cntL]<a[L-cntL-1]&&L-cntL>1)cntL++;
		{
			int Q=ansl>ansr-1?ansl:ansr-1;
			int P=cntR+1;
			if(Q<=P)
			{
				puts("0");
				return 0;
			}
		}
		{
			int Q=ansl-1>ansr?ansl-1:ansr;
			int P=cntL+1;
			if(Q<=P)
			{
				puts("0");
				return 0;
			}
		}
		int uu=0,cur=0,k=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>a[i-1])cur++;
			else
			{
				if(uu==cur)k++;
				if(uu<cur)k=1;
				uu=uu>cur?uu:cur;
				cur=1;
			}
		}
		
		if(uu==cur)k++;
		if(uu<cur)k=1;
		uu=uu>cur?uu:cur;
		cur=1;
		cur=0;a[0]=0x3f3f3f3f;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<a[i-1])cur++;
			else
			{
				if(uu==cur)k++;
				if(uu<cur)k=1;
				uu=uu>cur?uu:cur;
				cur=1;
			}
		}
		if(uu==cur)k++;
		if(uu<cur)k=1;
		uu=uu>cur?uu:cur;
		cur=1;
		if(uu>mx||(uu==mx&&k>2))puts("0");
		else puts("1");
	}
	else puts("0");
}