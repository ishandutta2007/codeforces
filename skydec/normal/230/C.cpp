#include<stdio.h>
using namespace std;
char p[101][20005];
long left[101][20005];
long right[101][20005];
long n,m;
long ans=2100000000;
int main()
{
	scanf("%ld%ld",&n,&m);
	for(long i=1;i<=n;i++)
	{
		bool flag=false;
		for(long j=1;j<=m;j++)
		{
			char q=getchar();
			while(q!='0'&&q!='1')q=getchar();
			p[i][j]=q;
			if(p[i][j]=='1')flag=true;
			p[i][m+j]=p[i][j];
		}
		if(!flag)
		{
			printf("-1\n");
			return 0;
		}
	}
	for(long i=1;i<=n;i++)
	{
		left[i][1]=0;right[i][2*m]=2*m+1;
		for(long j=2;j<=2*m;j++)
		{
			long y=j-1;while((y!=0)&&(p[i][y]=='0'))y=left[i][y];
			left[i][j]=y;
		}
		for(long j=2*m-1;j>=1;j--)
		{
			long y=j+1;while((y!=2*m+1)&&(p[i][y]=='0'))y=right[i][y];
			right[i][j]=y;
		}
	}
	for(long i=1;i<=2*m;i++)
	{
		long reu=0;
		for(long k=1;k<=n;k++)
		if(p[k][i]=='0')
		{
			long min=210000000;
			if(left[k][i]!=0)min=i-left[k][i];
			if(right[k][i]!=2*m+1&&right[k][i]-i<min)min=right[k][i]-i;
			reu+=min;
			if(reu>ans)break;
		}
		if(reu<ans)ans=reu;
	}
	printf("%ld\n",ans);
	return 0;
}