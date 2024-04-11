#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n,m,i,j,k,top;
char str[2000001];
bool ans;
bool t[2000001];
char st[2000001];

int main()
{
	//freopen("alternate.in","r",stdin);
	//freopen("alternate.out","w",stdout);
	scanf("%s",str+1);
	n=strlen(str+1);
	for(i=1;i<=n;++i)
	if(st[top]!=str[i])st[++top]=str[i];
	else --top;
	if(top)printf("No\n");
	else printf("Yes\n");
}