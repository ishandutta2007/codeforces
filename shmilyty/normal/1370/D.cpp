#include<bits/stdc++.h>
using namespace std;
int n,k,a[200001],l=1,r;
bool check(int p)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt&1)
		{
			if(a[i]<=p)
				cnt++;
		}
		else
			cnt++;		
	}	
	if(cnt>=k)
		return 1;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt&1)
			cnt++;
		else
		{
			if(a[i]<=p)
				cnt++;
		}
	}
	if(cnt>=k)
		return 1;
	return 0;
} 
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		r=max(r,a[i]); 
	}
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	cout<<l;
	return 0;
}