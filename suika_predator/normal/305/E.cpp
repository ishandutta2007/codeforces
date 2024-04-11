#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,qwq[5555],ok[5555],cnt[5555],pre[5555],nex[5555];
char str[5555];
int main()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	int last=0;
	qwq[0]=0,qwq[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=i;j++)cnt[j]=0;
		cnt[qwq[i-2]]++;
		for(int j=2;j<=i-1;j++)
		{
			cnt[qwq[j-2]^qwq[i-j-1]]++;
		}
		for(int j=0;j<=i;j++)
		{
			if(cnt[j]==0)
			{
				qwq[i]=j;
				break;
			}
		}
//		cout<<i<<' '<<qwq[i]<<endl;
	}
	for(int i=2;i<=n-1;i++)
	{
		if(str[i-1]==str[i+1])
			ok[i]=-1;
	}
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		if(!ok[i])
		{
			if(last!=0)
			{
				for(int j=last;j<i;j++)
				{
					nex[j]=i-1;
				}
				ans^=qwq[i-last];
				last=0;
			}
		}
		else
		{
			if(last==0)
			{
				last=i;
			}
			pre[i]=last;
		}
	}
	if(ans==0)return printf("Second\n"),0;
	printf("First\n");
	for(int i=2;i<=n-1;i++)
	{
		if(ok[i])
		{
			if(!ok[i-1]&&!ok[i+1])
			{
				if((ans^qwq[1])==0)
				{
					return printf("%d\n",i),0;
				}
			}
			else if(!ok[i-1]||!ok[i+1])
			{
				if((ans^qwq[nex[i]-pre[i]+1]^qwq[nex[i]-pre[i]-1])==0)
				{
					return printf("%d\n",i),0;
				}
			}
			else
			{
				if((ans^qwq[nex[i]-pre[i]+1]^qwq[i-pre[i]-1]^qwq[nex[i]-i-1])==0)
				{
					return printf("%d\n",i),0;
				}
			}
		}
	}
	return 0;
}