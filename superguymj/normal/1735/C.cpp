#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
const int N=1000005;
int n;
char s[N];
bool mt[26],vis[26];
int p[26],stk[26];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

bool check()
{
	rep(i,0,25) mt[i]=0;
	rep(i,0,25) if(!mt[i])
	{
		int x=i;
		for(; x!=-1 && !mt[x]; mt[x]=1,x=p[x]);
		if(x!=i) continue;
		return 0;
	}
	return 1;
}

void solve()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int tot=0;
	rep(i,0,25) vis[i]=0,p[i]=-1;
	rep(i,1,n)
	{
		int c=s[i]-'a';
		if(!vis[c])
		{
			vis[c]=1;
			stk[++tot]=c;
		}
	}
	rep(i,0,25) vis[i]=0;
	rep(i,1,tot)
	{
		int c=stk[i];
		rep(j,0,25) if(!vis[j])
		{
			p[c]=j;
			if(check())
			{
				vis[j]=1;
				break;
			}
		}
	}
	rep(i,1,n)
	{
		int c=s[i]-'a';
		putchar('a'+p[c]);
	}
	puts("");
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}