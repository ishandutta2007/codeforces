#include<map>
#include<set>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 300300

using namespace std;

char s[maxn],ch;
int n,m,l,k,x;
bool f;

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	l=0;k=0;
	f=true;
	for (int i=0;i<n;i++)
	{
		if (s[i]=='.')
		{
			k++;
			if (f) l++,f=false;
		}
		else f=true;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d %c",&x,&ch);x--;
		if (ch=='.'&&s[x]!='.')
		{
			k++;
			l=l+1-(x-1>=0&&s[x-1]=='.')-(x+1<n&&s[x+1]=='.');
		}
		else if (ch!='.'&&s[x]=='.')
		{
			if (s[x]=='.') k--;
			l=l-1+(x-1>=0&&s[x-1]=='.')+(x+1<n&&s[x+1]=='.');
		}
		s[x]=ch;
		printf("%d\n",k-l);
	}
	return 0;
}