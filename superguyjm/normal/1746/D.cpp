#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back

using namespace std;
const int N=200005;
typedef long long LL;
int n,s[N],p[N];
LL f[N][2],k;
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

bool cmp(int x,int y)
{
	return f[x][1]-f[x][0]>f[y][1]-f[y][0];
}

void dfs(int x,LL k)
{
	int d=vt[x].size();
	f[x][0]=k*s[x];
	f[x][1]=(k+1)*s[x];
	if(d==0)
		return;

	for(auto v:vt[x]) dfs(v,k/d);
	int b=k%d;
	int tot=0;
	for(auto v:vt[x]) f[x][0]+=f[v][0],f[x][1]+=f[v][0],p[++tot]=v;
	sort(p+1,p+1+tot,cmp);
	rep(i,1,b) f[x][0]+=f[p[i]][1]-f[p[i]][0];
	rep(i,1,b+1) f[x][1]+=f[p[i]][1]-f[p[i]][0];
}	

void solve()
{
	n=getint(),k=getint();
	rep(i,1,n) vt[i].clear();
	rep(i,2,n) vt[getint()].pb(i);
	rep(i,1,n) s[i]=getint();
	dfs(1,k);
	printf("%lld\n",f[1][0]);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}