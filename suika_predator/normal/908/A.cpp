#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>

using namespace std;

int n,m;
char str[233];
int main()
{
	scanf("%s",str);
	n=strlen(str);
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(str[i]=="13579aeiou"[j])cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}