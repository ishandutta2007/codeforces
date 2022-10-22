#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back

using namespace std;
typedef long long LL;
const int N=100005;
bool vis[N];
int n,cnt[N],b[N];
vector <int> vt[N],ans;

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
	return cnt[x]<cnt[y];
}

void dfs(int x)
{
	if(vis[x] || vt[x].empty()) return;
	vis[x]=1;
	if(1<=x && x<=n) dfs(b[x]);
	for(auto v:vt[x]) ans.pb(v);
}

void solve()
{
	n=getint();
	rep(i,0,n+1) cnt[i]=0,vt[i].clear();
	rep(i,1,n) ++cnt[b[i]=getint()],vt[b[i]].pb(i);
	int l=0,r=n;
	rep(i,0,n+1)
		sort(vt[i].begin(),vt[i].end(),cmp);
	rep(i,0,n+1)
	{
		for(auto x:vt[i])
			if(i<x) r=min(r,x-1);
			else l=max(l,x);
	}
	rep(i,0,n+1) vis[i]=0;
	ans.clear();
	rep(i,0,n+1)
		dfs(i);
	printf("%d\n",l);
	for(auto x:ans) printf("%d ",x);
	puts("");
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}