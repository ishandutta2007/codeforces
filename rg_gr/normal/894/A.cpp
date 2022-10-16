#include <stdio.h>
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>=48&&c<=57)num=num*10+(c^48),c=getchar();
	return num*f;
}
#include <string.h>
int main()
{
	int ans,p=ans=0;char c[105];
	scanf("%s",c);
	int n=strlen(c),L=0,R=n-1,t=0;
	for(int i=0;i<n;i++)p+=c[i]=='Q';
	for(int i=0;i<n;i++)
	{
		if(c[i]=='Q')t++;
		else if(c[i]=='A')ans+=t*(p-t);
	}
	printf("%d\n",ans);
	return 0;
}