#include <cstdio>
#include <iostream>
using namespace std;

int n,k,a[300007];

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	if(k==0)
	{
	    int lx1=0,mxlx1=0;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]==1)lx1++;
	        else lx1=0;
	        mxlx1=max(mxlx1,lx1);
	    }
	    printf("%d\n",mxlx1);
	    for(int i=0;i<n;i++)
    		printf("%d ",a[i]);
    	return 0;
	}
	int cnt=k,ans=-1;
	int changa,changb;
	for(int i=0,j=-1;i<n;i++)
	{
		while(j<n&&cnt>=0)
		{j++;if(!a[j])cnt--;}
		j--;cnt++;
		if(j-i+1>ans){ans=j-i+1;changa=i;changb=j;}
		if(!a[i])
			cnt++;
	}
	printf("%d\n",ans);
	for(int i=0;i<n;i++)
		if(i>=changa&&i<=changb)
			printf("1 ");
		else printf("%d ",a[i]);
	return 0;
}