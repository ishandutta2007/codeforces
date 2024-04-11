#include<bits/stdc++.h>
using namespace std;
int n,sum,a[101];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]*=10;
		sum+=a[i]; 
	}
	sort(a+1,a+1+n);
	if(sum/n>=45)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		sum+=50-a[i];
		if(sum/n>=45)
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}