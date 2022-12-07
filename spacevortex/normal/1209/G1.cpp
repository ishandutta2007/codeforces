#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,q;
int rd()
{
	int rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
int a[N],R[N],num[N];
int main()
{
	//freopen("d.in","r",stdin);
	int i,w,l,r,rmx,ans=0,val;
	n=rd();q=rd();
	for(i=1;i<=n;i++) a[i]=rd();
	for(i=n;i>=1;i--)
	{
		w=a[i];
		if(R[w]==0) {R[w]=i;}
		num[w]++;
	}
	l=1;
	while(l<=n)
	{
		r=l;rmx=l;val=0;
		while(r<=rmx)
		{
			w=a[r];
			rmx=max(rmx,R[w]);
			val=max(val,num[w]);
			r++;
		}
		ans+=r-l-val;
		l=rmx+1;
	}
	printf("%d\n",ans);
	return 0;
}