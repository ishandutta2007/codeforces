#include<bits/stdc++.h>
using namespace std;
int t,n,k,a[100001];
bool solve()
{
	bool kk=0;
	for(int i=1;i<=n;i++)
		if(a[i]==k)
		{
			kk=1;
			break;
		}
	if(!kk)
		return 0;
	if(n==1)
		return 1;
	for(int i=1;i<n;i++)
		if(a[i]>=k&&a[i+1]>=k)
			return 1;
	for(int i=1;i+1<n;i++)
		if(a[i]>=k&&a[i+2]>=k)
			return 1;
	return 0;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		puts(solve()?"Yes":"No");
	}
	return 0;
}