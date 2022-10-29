#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid ((l+r)>>1)
#define pb push_back

using namespace std;
const int N=200005;
int n,k,h,cnt,d[N];
vector <int> vt[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void dfs(int x)
{
	d[x]=1;
	for(auto v:vt[x])
	{
		dfs(v);
		if(d[v]==h && x>1) ++cnt;
		else d[x]=max(d[x],d[v]+1);
	}
}

bool check(int x)
{
	h=x,cnt=0;
	dfs(1);
	return cnt<=k;
}

void solve()
{
	n=getint(),k=getint();
	rep(i,1,n) vt[i].clear();
	rep(i,2,n) vt[getint()].pb(i);
	int l=1,r=n;
	while(l<=r) check(mid)?r=mid-1:l=mid+1;
	printf("%d\n",r+1);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}