#include<bits/stdc++.h>
using namespace std;


long long int arr[500001];

long long int sum1,sum2;
int cur1,cur2;

int main()
{
	int a,b,d,e,f,g,h,i,j,k=1,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,mini=100000,ans;
	
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&arr[i]);
	}
	m=n;
	
	sort(arr+1,arr+n+1);

	if(n==1)
	{
		printf("%d",arr[1]);
		return 0;
	}
	
	
	while(arr[k]<0&&k!=n)
	{
		arr[n]-=arr[k];
		k++;
		m--;
	}
	
	
	
	if(k!=n)
	{
		arr[n]-=arr[k];
		k++;
		if(arr[1]<0)
		{
			k--;
			arr[n]+=arr[k];
			arr[n]+=arr[k];
			k++;
		}
	}
	
	
	
	for(i=k;i<n;i++)
	{
		arr[n]+=arr[i];
	}
	
	
	printf("%lld",arr[n]);
	
}