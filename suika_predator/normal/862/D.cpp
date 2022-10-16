#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
char buf[2333];
int t0,t1,pos0,pos1,tmp;
int main()
{
	srand(time(0));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		buf[i]='0';
	}
	printf("? %s\n",buf+1);
	fflush(stdout);
	scanf("%d",&t1);
	t0=n-t1;
	buf[n]='1';
	printf("? %s\n",buf+1);
	fflush(stdout);
	scanf("%d",&tmp);
	if(tmp>t1)
	{
		pos0=n;
		int l=1,r=n-1;
		while(l<r)
		{
			for(int i=1;i<=n;i++)buf[i]='0';
			int mid=(l+r+1)/2;
			for(int i=mid;i<=n;i++)buf[i]='1';
			printf("? %s\n",buf+1);
			fflush(stdout);
			scanf("%d",&tmp);
			if(tmp==t1+n-mid+1)r=mid-1;
			else l=mid;
		}
		pos1=l;
	}
	else
	{
		pos1=n;
		int l=1,r=n-1;
		while(l<r)
		{
			for(int i=1;i<=n;i++)buf[i]='1';
			int mid=(l+r+1)/2;
			for(int i=mid;i<=n;i++)buf[i]='0';
			printf("? %s\n",buf+1);
			fflush(stdout);
			scanf("%d",&tmp);
			if(tmp==t0+n-mid+1)r=mid-1;
			else l=mid;
		}
		pos0=l;
	}
	printf("! %d %d\n",pos0,pos1);
	fflush(stdout);
	return 0;
}