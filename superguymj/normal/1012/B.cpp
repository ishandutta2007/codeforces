#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=200005;
bool vis[N];
int n,m,q,fa[N],ans,x,y;
vector <int> vt[N];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

int getfa(int x)
{
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}

void merge(int x,int y)
{
	x=getfa(x),y=getfa(y);
	if(x!=y) fa[x]=y;
}

int main()
{
	n=getint(),m=getint(),q=getint();
	rep(i,1,q) x=getint(),y=getint(),vt[y].push_back(x),vis[y]=1;
	rep(i,1,n) fa[i]=i;
	rep(i,1,m)
	{
		int siz=vt[i].size()-1;
		rep(j,0,siz-1) merge(vt[i][j],vt[i][j+1]);
	}
	ans=-1;
	rep(i,1,n) if(getfa(i)==i) ++ans;
	rep(i,1,m) if(!vis[i]) ++ans;
	printf("%d\n",ans);
	return 0;
}