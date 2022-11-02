#include<cstdio>
#include<cstring>

using namespace std;

int i,l,ans,last;
char b[5001];

int main()
{
	scanf("%s",b+1);
	l=strlen(b+1);
	for(i=1;i<=l;i++)
	if(b[i]=='b'&&b[i+1]=='e'&&b[i+2]=='a'&&b[i+3]=='r')ans+=(i-last)*(l-i-2),last=i;
	printf("%d",ans);
}