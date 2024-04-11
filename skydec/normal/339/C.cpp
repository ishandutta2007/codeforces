#include<stdio.h>
using namespace std;
bool have[11]={false};
long m;bool flag=false;
long temp[1005];
void dfs(long step,long l,long r)
{
	if(flag)return;
	if(step>m)
	{
		flag=true;
		printf("YES\n");
		for(long i=1;i<=m-1;i++)printf("%ld ",temp[i]);
		printf("%ld",temp[m]);
		return;
	}
	for(long i=1;i<=10;i++)
	if(have[i]&&(i!=temp[step-1]))
	{
		if(step&1)
		{
			if(i+l>r)
			{
				temp[step]=i;
				dfs(step+1,i+l,r);
			}
		}
		else
		{
			if(i+r>l)
			{
				temp[step]=i;
				dfs(step+1,l,r+i);
			}
		}
	}
}
int main()
{
	for(long i=1;i<=10;i++)
	{
		char p=getchar();
		have[i]=p-'0';
	}
	scanf("%ld",&m);temp[0]=-1;
	dfs(1,0,0);
	if(!flag)printf("NO");
	//for(;;);
	return 0;
}