#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,m;
char buf[233333],op;
int flag[233],tmp[233];
int cnt,shock;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<26;i++)flag[i]=1;
	cnt=26;
	for(int o=1;o<n;o++)
	{
		for(int i=0;i<26;i++)tmp[i]=0;
		scanf(" %c %s",&op,buf);
		int len=strlen(buf);
		for(int i=0;i<len;i++)tmp[buf[i]-'a']=1;
		if(cnt!=1)
		{
			if(op=='.')
			{
				for(int i=0;i<26;i++)
					if(tmp[i])
						if(flag[i])
						{
							//cout<<i<<endl;
							flag[i]=0;
							cnt--;
						}
			}
			else if(op=='!')
			{
				for(int i=0;i<26;i++)
					if(tmp[i]==0)
						if(flag[i])
						{
							//cout<<i<<endl;
							flag[i]=0;
							cnt--;
						}
			}
			else
			{
				if(flag[buf[0]-'a'])
				{
					flag[buf[0]-'a']=0;
					cnt--;
				}
			}
		}
		else
		{
			if(op=='!'||op=='?')shock++;
		}
	}
	printf("%d\n",shock);
	return 0;
}