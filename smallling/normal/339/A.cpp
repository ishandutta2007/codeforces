#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int i,j,k,l,m,n,o,p;
char ch[10001],s[10001];

int main()
{
	scanf("%s",s+1);
	l=strlen(s+1);
	o=0;
	for(i=1;i<=l;i++)
	{
		if(s[i]=='+')ch[++o]=s[i-1];
	}
	ch[++o]=s[l];
	sort(ch+1,ch+1+o);
	for(i=1;i<o;i++)
	printf("%c+",ch[i]);
	printf("%c",ch[o]);
}