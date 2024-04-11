#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
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
int n,x,y,a,b;

int main()
{
	n=getint();
	rep(i,1,n)
	{
		x=getint(),y=getint();
		if(x<0) ++a;
		else ++b;
	}
	if(a<=1 || b<=1) puts("Yes");
	else puts("No");
	return 0;
}