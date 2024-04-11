#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
char str[23333];
int main()
{
	scanf("%s",str);
	int len=strlen(str);
	int c=0,d=0;
	for(int i=0;i<len;i++)
	{
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')c=d=0;
		else
		{
			if(c&&str[i]!=str[i-1])d=1;
			c++;
			if(c>=3&&d)
			{
				printf(" ");
				c=1,d=0;
			}
		}
		printf("%c",str[i]);
	}
	return 0;
}