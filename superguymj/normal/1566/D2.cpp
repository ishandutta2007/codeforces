#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#include<map>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back
 
using namespace std;
const int N=100005;
int n,m,a[N],ID[N],ans,b[N];
map <int,int> mp,p[N];
 
int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}
 
int id(int x,int y)
{
	return (x-1)*m+y;
}
 
void solve()
{
	n=getint(),m=getint();
	rep(i,1,n*m) a[i]=b[i]=getint();
	sort(b+1,b+1+n*m);
	mp.clear();
	rep(i,1,n)
	{
		repd(j,m,1)
		{
			int x=++mp[b[id(i,j)]];
			p[x][b[id(i,j)]]=id(i,j);
		}
	}
	mp.clear();
	rep(i,1,n*m)
	{
		int x=++mp[a[i]];
		ID[p[x][a[i]]]=i;
	}
	ans=0;
	rep(i,1,n)
		rep(j,1,m)
			rep(k,j+1,m) 
				if(ID[id(i,j)]<ID[id(i,k)]) ++ans;
	printf("%d\n",ans);
}
 
int main()
{	
	int T=getint();
	while(T--) solve();
	return 0;
}