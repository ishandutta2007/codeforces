#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back
 
using namespace std;
const int N=305;
int n,m,a[N],id[N],ans;
 
int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}
 
bool cmp(int x,int y)
{
	return a[x]==a[y]?x>y:a[x]<a[y];
}
 
void solve()
{
	n=getint(),m=getint();
	rep(i,1,m) a[i]=getint();
	rep(i,1,m) id[i]=i;
	sort(id+1,id+1+m,cmp);
	ans=0;
	rep(i,1,m) rep(j,i+1,m) if(id[i]<id[j]) ++ans;
	printf("%d\n",ans);
}
 
int main()
{	
	int T=getint();
	while(T--) solve();
	return 0;
}