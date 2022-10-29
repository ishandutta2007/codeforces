#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)

using namespace std;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;	
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void solve()
{
	int A=getint()-1,B=getint();
	int x=(A&3),y=B;
	rep(i,0,x) y^=(A-i);
	if(y==0) printf("%d\n",A+1);
	else if(y==A+1) printf("%d\n",A+3);
	else printf("%d\n",A+2);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}