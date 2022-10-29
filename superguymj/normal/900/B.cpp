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
int a,b,c,tot,nw;
bool vis[1000005];

int main()
{
	a=getint(),b=getint(),c=getint();
	while(1)
	{
		if(vis[a]) return puts("-1"),0;
		vis[a]=1,++tot,a=a*10,nw=a/b,a=a%b;
		if(nw==c) return printf("%d\n",tot),0;
	}
	return 0;
}