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
int t,n,a[501];
map<int,int> num;
vector<array<int,2>> ans1;
vector<int> ans2;
deque<int> q1,q2;
void solve()
{
	n=read();
	q1.clear();
	q2.clear();
	ans1.clear();
	ans2.clear();
	num.clear();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		q2.push_back(a[i]);
		num[a[i]]++;
	}
	for(auto l:num)
		if(l.second&1)
		{
			puts("-1");
			return ;
		}
	int tot=0;
	while(!q2.empty())
		if(q1.empty()||q1.front()!=q2.front())
		{
			q1.push_back(q2.front());
			q2.pop_front();
		}
		else
		{
			ans2.push_back(q1.size()*2);
			tot+=q1.size()+1;
			q1.pop_front();
			q2.pop_front();
			while(!q1.empty())
			{
				ans1.push_back({tot,q1.front()});
				q2.push_front(q1.front());
				q1.pop_front();
				tot++;
			}
		}
	cout<<ans1.size()<<endl;
	for(auto i:ans1)
		cout<<i[0]<<" "<<i[1]<<'\n';
	cout<<ans2.size()<<endl;
	for(int i:ans2)
		cout<<i<<' ';
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}