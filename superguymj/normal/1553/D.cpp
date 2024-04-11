#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=100005;
int n,m;
char s[N],t[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

bool find(int x,int y)
{
	if(y>m)
	{
		int len=n-x+1;
		if(len&1) return 0;
		return 1;
	}
	if(x>n) return 0;
	if(s[x]==t[y]) return find(x+1,y+1);
	else return find(x+2,y);
}

void solve()
{
	scanf("%s",s+1),n=strlen(s+1);
	scanf("%s",t+1),m=strlen(t+1);
	bool jdg=0;
	rep(i,1,n) if(i&1 && s[i]==t[1])
	{
		if(find(i,1)) jdg=1;
		break;
	}
	rep(i,1,n) if((i^1)&1 && s[i]==t[1])
	{
		if(find(i,1)) jdg=1;
		break;
	}
	if(jdg) puts("YES");
	else puts("NO");
}

int main()
{
	int T=getint();
	while(T--) solve();
}