#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)

using namespace std;
const int N=105;
int n;
char s[N],t[N];

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
	n=getint(),scanf("%s",s+1);
	rep(i,1,n) if(s[i]=='L' || s[i]=='R') t[i]=s[i]; else if(s[i]=='U') t[i]='D'; else t[i]='U';
	rep(i,1,n) putchar(t[i]);
	puts("");
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}