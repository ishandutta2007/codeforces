#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=200005;
typedef long long LL;
int n,k,a[N];
map <int,bool> mp;

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
	n=getint(),k=getint();
	rep(i,1,n) a[i]=getint();
	mp.clear();
	rep(i,1,n) mp[a[i]]=1;
	rep(i,1,n) if(mp[a[i]-k])
	{
		puts("YES");
		return;
	}
	puts("NO");
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}