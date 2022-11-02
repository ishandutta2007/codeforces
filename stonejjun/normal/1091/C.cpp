#include<bits/stdc++.h>
using namespace std;
long long int arr[10000000];
long long int arr2[10000000];
int main()
{
	long long int a,b=0,c=0,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,idx=0;
	scanf("%lld",&n);
	long long int sq=sqrt(n);
	for(i=1;i<=sq;i++)
	{
		if(n%i==0)
		{
			idx++;
			arr[idx]=i;
			if(i!=n/i)
			{
			idx++;
			arr[idx]=n/i;
			}
		}
	}

	long long int sum=n*(n+1)/2;

	for(i=1;i<=idx;i++)
	{
		arr2[i]=(sum-((n*(arr[i]-1))/2))/arr[i];
	}

	sort(arr2+1,arr2+1+idx);
	for(i=1;i<=idx;i++)
	{
		printf("%lld ",arr2[i]);
	}

}