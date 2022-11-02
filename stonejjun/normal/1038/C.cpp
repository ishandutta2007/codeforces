#include<bits/stdc++.h>
using namespace std;


int arr[100001];
int arr2[100001];
char c[100003];

long long int sum1,sum2;
int cur1,cur2;

int main()
{
	int a,b,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,mini=100000,ans;
	
	
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&arr2[i]);
	}
	
	sort(arr+1,arr+n+1);
	sort(arr2+1,arr2+n+1);

	cur1=n;
	cur2=n;
	
	while(cur1!=0||cur2!=0)
	{
		if(arr[cur1]<arr2[cur2])
		{
			cur2--;
		}
		else
		{
			sum1+=arr[cur1];
			cur1--;
		}
		
		if(arr2[cur2]<arr[cur1])
		{
			cur1--;
		}
		else
		{
			sum2+=arr2[cur2];
			cur2--;
		}
		
	}
	
	printf("%lld",sum1-sum2);
		
	
}