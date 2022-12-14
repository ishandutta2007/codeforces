#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
int x[50010],y[50010],p[50010],b[50010],pr[50010],ans=0,now[10010];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("? 0 %d\n",i-1);
		fflush(stdout);
		scanf("%d",&x[i-1]);
	}
	for(int i=1;i<=n;i++)
	{
		printf("? %d 0\n",i-1);
		fflush(stdout);
		scanf("%d",&y[i-1]);
	}	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			p[j]=y[j]^y[i];
		}
		int can=1;
		for(int j=0;j<n;j++)
			if(p[j]<0||p[j]>=n||now[p[j]]==i+1)
				can=0;
			else
			{
				now[p[j]]=i+1;
				b[p[j]]=j;
			}
		if(can)
		{
			int z=0;
			for(int j=0;j<n;j++)
				if(b[j]==0)
					z=j;
			int is=1;
			for(int j=0;j<n;j++)
				if(b[j]!=(x[j]^x[z]))
					is=0;
			if((b[0]^p[0])!=x[0])
				is=0;
			if(is)
			{		
			/*	for(int j=0;j<n;j++)
					cout<<p[j]<<' ';
				for(int j=0;j<n;j++)
					cout<<b[j]<<' ';	
				cout<<(p[0]^b[0])<<endl;*/
				ans++;
				if(ans==1)
					for(int j=0;j<n;j++)
						pr[j]=p[j];
			}
		}
	}
	printf("!\n");
	printf("%d\n",ans);
	for(int i=0;i<n;i++)
		printf("%d ",pr[i]);
	cout<<endl;
	fflush(stdout);
}