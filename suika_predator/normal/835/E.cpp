#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n,x,y,ans,xr;
int arr[2333],top;
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	for(int bit=1;bit<=1<<9;bit<<=1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)if(i&bit)cnt++;
		if(cnt==0)break;
		printf("? %d",cnt);
		for(int i=1;i<=n;i++)if(i&bit)printf(" %d",i);
		printf("\n");
		fflush(stdout);
		scanf("%d",&ans);
		if(ans==y||ans==(x^y))xr|=bit;
	}
	//cout<<xr<<endl;
	int lb=xr&-xr;
	for(int i=1;i<=n;i++)if(i&lb)arr[++top]=i;
	int l=1,r=top;
	while(l<r)
	{
		int mid=(l+r)/2;
		printf("? %d",mid-l+1);
		for(int i=l;i<=mid;i++)
		{
			printf(" %d",arr[i]);
		}
		printf("\n");
		fflush(stdout);
		scanf("%d",&ans);
		if(ans==y||ans==(x^y))r=mid;
		else l=mid+1;
	}
	int a=arr[l],b=a^xr;
	if(a>b)swap(a,b);
	printf("! %d %d\n",a,b);
	fflush(stdout);
	return 0;
}