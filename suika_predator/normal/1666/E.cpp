#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 210000;

int n,L;
int a[maxn],b[maxn];
int li[maxn],ri[maxn];
int D1,D2;

int judge(const int d,const int u)
{
	li[1]=ri[1]=0;
	for(int i=1;i<=n;i++)
	{
		if( li[i]>ri[i] ) return 0;
		
		int l=li[i]+d,r=ri[i]+u;
		if(i+1<=n)
		{
			l=max(l,a[i]);
			r=min(r,a[i+1]);
		}
		else
		{
			l=max(l,L);
			r=min(r,L);
		}
		li[i+1]=l,ri[i+1]=r;
	}
	
	if( li[n+1]>ri[n+1] ) return 0;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>L>>n;
	D1= L/n;
	D2= D1 + (L%n!=0);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	int l=1,r=D1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(judge(mid,L)) l=mid+1;
		else r=mid-1;
	}
	int D=l-1;
	
	l=D2,r=L;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(judge(D,mid)) r=mid-1;
		else l=mid+1;
	}
	int U=r+1;
	
	judge(D,U);
	b[n+1]=L;
	for(int i=n;i>=1;i--)
	{
		b[i]=max( li[i],b[i+1]-U );
	}
	//b[1]=0;
	
	for(int i=1;i<=n;i++) cout<<b[i]<<' '<<b[i+1]<<'\n';
	
	return 0;
}