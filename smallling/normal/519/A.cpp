#include<cstdio>
#include<cstring>

using namespace std;

int len,sum1,sum2;
char s[100010];

int main()
{
	for(int i=1;i<=8;i++)
	{
		scanf("%s",s);
		len=strlen(s);
		for(int i=0;i<len;i++)
		{
			if(s[i]=='Q')sum1+=9;
			if(s[i]=='q')sum2+=9;
			if(s[i]=='R')sum1+=5;
			if(s[i]=='r')sum2+=5;
			if(s[i]=='B'||s[i]=='N')sum1+=3;
			if(s[i]=='b'||s[i]=='n')sum2+=3;
			if(s[i]=='P')sum1++;
			if(s[i]=='p')sum2++;
		}
	}
	if(sum1==sum2)puts("Draw");
	if(sum1>sum2)puts("White");
	if(sum1<sum2)puts("Black");
}