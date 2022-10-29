#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int T,n;
char s[105];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		int x=0,y=0;
		rep(i,1,2*n-1) if(s[i]=='0') ++x; else ++y;
		if(x>y) rep(i,1,n) putchar('0');
		else rep(i,1,n) putchar('1');
		puts("");
	}
	return 0;
}