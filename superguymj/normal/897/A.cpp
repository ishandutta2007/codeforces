#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}
int n,m,l,r;
char s[1000],a[10],b[10];

int main()
{
	n=getint(),m=getint();
	scanf("%s",s+1);
	while(m--)
	{
		l=getint(),r=getint(),scanf("%s%s",a,b);
		rep(i,l,r) if(s[i]==a[0]) s[i]=b[0];
	}
	rep(i,1,n) printf("%c",s[i]);
	puts("");
	return 0;
}