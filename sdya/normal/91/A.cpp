#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

char s1[11000];
char s2[1100000];

int n, m;
int nt[11000][26];
int fs[11000];

int main()
{
	gets(s1);
	gets(s2);
	n=strlen(s1);
	m=strlen(s2);
	for (int i=0; i<26; i++)
	{
		fs[i]=-1;
		for (int j=0; j<n; j++)
			if (s1[j]==i+'a') {fs[i] = j; break;}
	}
	for (int i=n-1; i>=0; i--)
	{
		for (int j=0; j<26; j++)
			nt[i][j]=-1;
		if (i==n-1) continue;
		for (int j=0; j<26; j++)
			if (s1[i+1] == j+'a') nt[i][j]=i+1; else nt[i][j]=nt[i+1][j];
	}

	int res = 1;
	int cur = fs[s2[0]-'a'];
	if (fs[s2[0]-'a']==-1)
	{
		printf("-1\n");
		return 0;
	}
	for (int i=1; i<m; i++)
	{
		if (nt[cur][s2[i]-'a']==-1)
		{
			if (fs[s2[i]-'a']==-1)
			{
				printf("-1\n");
				return 0;
			}
			res++;
			cur=fs[s2[i]-'a'];
		} else
			cur=nt[cur][s2[i]-'a'];
	}

	printf("%d\n", res);
	return 0;
}