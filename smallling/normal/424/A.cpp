#include<cstdio>
#include<algorithm>

using namespace std;

int n,o,p;
char s[1001];

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='x')o++;
		else p++;
	printf("%d\n",abs(o-n/2));
	if(o>n/2)o=o-n/2;
	else o=0;
	if(p>n/2)p=p-n/2;
	else p=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='x'&&o>0){printf("X"),o--;continue;}
		if(s[i]=='X'&&p>0){printf("x"),p--;continue;}
		printf("%c",s[i]);
	}
}