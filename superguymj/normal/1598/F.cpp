#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=22;
string s[N];
bool vis[1<<20];
pair <int,int> dat[N],f[1<<20];
int n,ans,g[N][400005];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;	
	return x;
}

pair <int,int> find(string s,int x)
{
	int n=s.length();
	pair<int,int> ret=make_pair(0,0);	
	rep(i,0,n-1)
	{
		if(s[i]=='(') ++ret.second;
		else if(ret.second) --ret.second;
		else ++ret.first;
		if(ret.second==0) ++g[x][ret.first];
	}
	return ret;
}

pair <int,int> operator + (pair <int,int> x,pair <int,int> y)
{
	if(y.first<=x.second) x.second+=-y.first+y.second;
	else x.first+=y.first-x.second,x.second=y.second;
	return x;
}

void solve()
{
	n=getint();
	rep(i,1,n) cin>>s[i],dat[i]=find(s[i],i);
	vis[0]=1,f[0]=make_pair(0,0);
	rep(i,0,(1<<n)-2) if(vis[i])
	{
		rep(j,1,n) if(!(i&(1<<j-1)))
		{
			pair <int,int> S=make_pair(0,f[i].first);
			S=S+dat[j];
			ans=max(ans,f[i].second+g[j][f[i].first]);
			if(S.first==0)
			{
				vis[i^(1<<j-1)]=1;
				f[i^(1<<j-1)].first=S.second;
				f[i^(1<<j-1)].second=max(f[i^(1<<j-1)].second,f[i].second+g[j][f[i].first]);
			}
		}
	}
	printf("%d\n",ans);
}

int main()
{
	solve();
	return 0;
}