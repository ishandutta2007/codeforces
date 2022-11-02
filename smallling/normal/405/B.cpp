#include<cstdio>
#include<cstring>

using namespace std;

int i,j,k,l,m,n,o,p,ans,bo,b,bb;
char s[3001];

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	l=strlen(s+1);
	o=0;
	for(i=1;i<=l;i++)
	{
		if(s[i]=='R'){ans=i-1;break;}
		if(s[i]=='L')break;
	}
	if(i>n)ans=n;
	if(s[i]=='R')bo=1;
	for(j=i+1;j<=l;j++)
	{
		if(bo==1&&s[j]=='L'){if(bb&1)ans++;bo=0,bb=0;}
		if(s[j]=='R')bo=1;
		if(bo==0&&s[j]=='.')ans++;
		if(bo==1&&s[j]=='.')bb++;
	}
	printf("%d",ans);
}