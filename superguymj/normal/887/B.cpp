#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n,tot,c[10],ans,bit[10];
bool f[10][20],vis;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

void dfs(int x,int S)
{
	if(x>tot) {vis=1; return;}
	rep(i,1,n)
		if(f[i][c[x]] && !(S&(1<<i-1)))
		{
			dfs(x+1,S|(1<<i-1));
			if(vis) return;
		}
}

bool check(int x)
{
	vis=tot=0;
	while(x) c[++tot]=x%10,x/=10;
	return dfs(1,0),vis;
}

int main()
{
	n=getint();
	rep(i,1,n)
		rep(j,1,6)
			f[i][getint()]=1;
	rep(i,1,999)
		if(!check(i))
		{
			printf("%d\n",i-1);
			return 0;
		}
	puts("999");
	return 0;
}