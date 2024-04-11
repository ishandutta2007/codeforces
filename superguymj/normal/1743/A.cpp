#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid ((l+r)>>1)
#define pb push_back

using namespace std;
int n,ans,cnt[20];
bool vis[20];
set <int> st;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

bool check(int x)
{
	rep(i,0,3)
	{
		if(vis[x%10]) return 0;
		x/=10;
	}
	return 1;
}

void solve()
{
	n=getint();
	rep(i,0,9) vis[i]=0;
	rep(i,1,n)
		vis[getint()]=1;
	ans=0;
	rep(i,0,9999) if(check(i))
	{
		st.clear();
		int x=i;
		rep(j,0,9) cnt[j]=0;
		rep(j,0,3) st.insert(x%10),++cnt[x%10],x/=10;
		if(st.size()==2)
		{
			if(cnt[*st.begin()]==2)
				++ans;
		}
	}
	printf("%d\n",ans);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}