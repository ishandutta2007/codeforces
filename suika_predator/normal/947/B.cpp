#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m;
int v[233333],t[233333];
long long st[233333],ans[233333],del[233333];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	for(int i=1;i<=n;i++)scanf("%d",&t[i]),st[i]=st[i-1]+t[i];
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n+1;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(st[mid]-st[i-1]>=v[i])r=mid;
			else l=mid+1;
		}
		ans[i]++;ans[l+1]--;del[l]+=st[l]-st[i-1]-v[i];
//		cout<<i<<' '<<l<<endl;
	}
//	for(int i=1;i<=n+2;i++)cout<<ans[i]<<' ';cout<<endl;
	for(int i=1;i<=n;i++)ans[i]+=ans[i-1];
	for(int i=1;i<=n;i++)ans[i]*=t[i],ans[i]-=del[i];
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
	return 0;
}