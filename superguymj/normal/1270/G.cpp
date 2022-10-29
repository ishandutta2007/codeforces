#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=1000005;
bool vis[N];
int n,a[N],ans[N];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

void solve()
{
	n=getint();
	rep(i,1,n) a[i]=i-getint(),vis[i]=0;
	int x=1;
	while(!vis[x]) vis[x]=1,x=a[x];
	int y=a[x];
	ans[*ans=1]=x;
	while(y!=x) ans[++*ans]=y,y=a[y];
	printf("%d\n",*ans);
	rep(i,1,*ans) printf("%d ",ans[i]);
	puts("");
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}