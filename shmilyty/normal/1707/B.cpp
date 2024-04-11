#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int t,n,cnt;
vector<int> a,b;
void solve()
{
	n=read();
	cnt=0;
	a.clear();
	for(int i=1;i<=n;i++)
		a.push_back(read());
	// cout<<n<<endl;
	while(a.size()>1)
	{
		b.clear();
		if(cnt)
		{
			cnt--;
			b.push_back(a[0]);
		}
		for(int i=1;i<a.size();i++)
			b.push_back(a[i]-a[i-1]);
		sort(ALL(b));
		a.clear();
		for(int i:b)
			if(!i)
				cnt++;
			else
				a.push_back(i);
		// cout<<a.size()<<endl;
	}
	if(a.empty())
		puts("0");
	else
		cout<<a[0]<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}