#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=10005;
int n,m,tot,nxt[N];
char s[N],t[N],tmp[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

bool check(int x)
{
	rep(i,1,x)
	{
		if(2*x-i>m) continue;
		if(t[i]!=t[2*x-i]) return 0;
	}
	tot=0;
	int y=2*x;
	if(y<=m)
		repd(i,m,y) tmp[++tot]=t[i];
	rep(i,1,x) tmp[++tot]=t[i];
	return 1;
}

bool in()
{
	nxt[1]=0;
	rep(i,2,tot)
	{
		int k=nxt[i-1];
		while(k && tmp[k+1]!=tmp[i]) k=nxt[k];
		if(tmp[k+1]==tmp[i]) ++k;
		nxt[i]=k;
	}
	int lst=0;
	rep(i,1,n)
	{
		while(lst && tmp[lst+1]!=s[i]) lst=nxt[lst];
		if(tmp[lst+1]==s[i]) ++lst;
		if(lst==tot) return 1;
	}
	return 0;
}

void solve()
{
	scanf("%s",s+1),n=strlen(s+1);
	scanf("%s",t+1),m=strlen(t+1);
	bool jdg=0;
	rep(i,1,m) if(check(i))
	{
		if(in()) {jdg=1; break;}
	}
	if(jdg) puts("YES");
	else puts("NO");
}

int main()
{
	int T=getint();
	while(T--) solve();
}