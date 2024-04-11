#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;char s[10];
int main()
{
	scanf("%d%s",&n,s);
	int p=strlen(s);
	reverse(s,s+p);
	int m=0;
	for(int i=0;i<p;i++)m*=10,m+=s[i]-'0';
	printf("%d\n",n+m);
	return 0;
}