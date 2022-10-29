#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
int n,p[60005];
bool vis[60005];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int main()
{
	n=getint();
	if(n&1)
	{
		long long tot=(n+1ll)*n/2;
		if(tot&1) puts("1");
		else puts("0");
		tot/=2;
		repd(i,n,1)
		{
			if(tot<=n && !vis[tot])
			{
				p[++*p]=tot;
				break;
			}
			if(tot>i) p[++*p]=i,vis[i]=1,tot-=i;
		}
		printf("%d",*p);
		rep(i,1,*p) printf(" %d",p[i]);
		puts("");
	}
	else
	{
		if((n>>1)&1) puts("1");
		else puts("0");
		printf("%d",n>>1);
		rep(i,1,n>>2) printf(" %d %d",i,n-i+1);
		if((n>>1)&1) printf(" %d",n>>1);
		puts("");
	}
	return 0;
}