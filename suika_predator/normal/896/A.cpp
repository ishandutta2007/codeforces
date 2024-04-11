#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,q;
long long m;
char str[]="What are you doing at the end of the world? Are you busy? Will you save us?";
char str2[]="What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
char part1[]="What are you doing while sending \"";
char part2[]="\"? Are you busy? Will you send \"";
char part3[]="\"?";
long long len[66];
int len1,len2,len3;
int main()
{
	len[0]=strlen(str);
	len1=strlen(part1);
	len2=strlen(part2);
	len3=strlen(part3);
	for(int i=1;i<=53;i++)
	{
		len[i]=2*len[i-1]+strlen(str2);
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%I64d",&n,&m);
		if(n<=53&&m>len[n])
		{
			printf(".");
			continue;
		}
		for(int i=n;i>=0;i--)
		{
			if(i==0)
			{
				printf("%c",str[m-1]);
				break;
			}
			if(m<=len1)
			{
				printf("%c",part1[m-1]);
				break;
			}
			m-=len1;
			if(i<=53)
			{
				if(m>len[i-1])
				{
					m-=len[i-1];
					if(m<=len2)
					{
						printf("%c",part2[m-1]);
						break;
					}
					m-=len2;
				}
				if(m>len[i-1])
				{
					m-=len[i-1];
					if(m<=len3)
					{
						printf("%c",part3[m-1]);
						break;
					}
					m-=len3;
				}
			}
		}
	}
	return 0;
}