#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int a[233333],b[233333],c[233333];
long long calc(int x,int y,int z)
{
	return 1ll*(y-x)*(y-x)+1ll*(x-z)*(x-z)+1ll*(y-z)*(y-z);
}
long long calcc(int x,int y)
{
	int l=1,r=k;
	long long ans=0x3f3f3f3f3f3f3f3fll;
	while(r-l>2)
	{
		int ml=(l+l+r)/3,mr=(l+r+r)/3;
		long long sl=calc(x,y,c[ml]),sr=calc(x,y,c[mr]);
		ans=min(ans,sl);
		ans=min(ans,sr);
		if(sl<sr)r=mr;
		else l=ml;
	}
	for(int i=l;i<=r;i++)
	{
		ans=min(ans,calc(x,y,c[i]));
	}
	return ans;
}
long long calcb(int x)
{
	int l=1,r=m;
	long long ans=0x3f3f3f3f3f3f3f3fll;
	while(r-l>2)
	{
		int ml=(l+l+r)/3,mr=(l+r+r)/3;
		long long sl=calcc(x,b[ml]),sr=calcc(x,b[mr]);
		ans=min(ans,sl);
		ans=min(ans,sr);
		if(sl<sr)r=mr;
		else l=ml;
	}
	for(int i=l;i<=r;i++)
	{
		ans=min(ans,calcc(x,b[i]));
	}
	return ans;
}
int t[111111];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		//----------------------
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		int z=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i-1])
				t[++z]=a[i];
		}
		for(int i=1;i<=z;i++)
			a[i]=t[i];
		n=z;
		//----------------------
		for(int i=1;i<=m;i++)
		{
			cin>>b[i];
		}
		sort(b+1,b+m+1);
		z=0;
		for(int i=1;i<=m;i++)
		{
			if(b[i]!=b[i-1])
				t[++z]=b[i];
		}
		for(int i=1;i<=z;i++)
			b[i]=t[i];
		m=z;
		//----------------------
		for(int i=1;i<=k;i++)
		{
			cin>>c[i];
		}
		sort(c+1,c+k+1);
		z=0;
		for(int i=1;i<=k;i++)
		{
			if(c[i]!=c[i-1])
				t[++z]=c[i];
		}
		for(int i=1;i<=z;i++)
			c[i]=t[i];
		k=z;
		long long ans=0x3f3f3f3f3f3f3f3fll;
		for(int i=1;i<=n;i++)
		{
			ans=min(ans,calcb(a[i]));
		}
		cout<<ans<<endl;
	}
	
	return 0;
}