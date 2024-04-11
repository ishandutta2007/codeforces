#include<iostream>
#include<cstdio>
#include<cstring>
#define N 101
using namespace std;
int n,k,num[26];
char s[N];
int main()
{
	scanf("%d%d%s",&n,&k,s);
	for(int i=0;i<n;i++)
	{
		num[s[i]-'a'];
		if(++num[s[i]-'a']>k)
		{puts("NO");return 0;} 
	}
	puts("YES");
}