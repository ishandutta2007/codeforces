#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int canbe[26];
char str[100007];
bool gsd=0;
int syd=0;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<26;i++)canbe[i]=1;
	for(int i=0;i<n;i++)
	{
		char id;
		scanf(" %c",&id);
		if(i==n-1)break;
		if(id=='.')
		{
			scanf("%s",str);
			for(int j=0;str[j];j++)canbe[str[j]-'a']=0;
		}
		else if(id=='!')
		{
			scanf("%s",str);
			if(gsd)
			{
				syd++;
				continue;
			}
			for(int j=0;str[j];j++)if(canbe[str[j]-'a']<2)canbe[str[j]-'a']+=2;
			for(int i=0;i<26;i++)
				if(canbe[i]<=2)canbe[i]=0;
				else canbe[i]=1;
		}
		else
		{
			char s;
			scanf(" %c",&s);
			if(gsd)
			{
				syd++;
				continue;
			}
			canbe[s-'a']=0;
		}
		int cnt=0;
		for(int i=0;i<26;i++)cnt+=canbe[i];
		if(cnt==1)gsd=1;
	}
	printf("%d\n",syd);
	return 0;
}