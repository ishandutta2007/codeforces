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
const int mod=998244353;
int n,pre=1,ans=1;
string s;
struct node
{
	std::vector<int> v;
	int f;
	bool add(int x)
	{
		while(!v.empty())
		{
			if(v.back()==x+1)
			{
				v.pop_back();
				x+=2;
			}
			else
				break;
		}
		if(!v.empty()&&v.back()<=x)
			return 0;
		v.push_back(x);
		return 1;
	}
};
vector<node> v1;
signed main()
{
	n=read();
	while(n--)
	{
		cin>>s;
		for(char i:s)
		{
			vector<node> v2;
			i-='0';
			int x=ans;
			ans=(pre+mod-ans)%mod;
			for(auto l:v1)
				if(l.add(i))
				{
					if(l.v.size()==1)
						(ans+=mod-l.f)%=mod;
					v2.push_back(l);
				}
			if(i)
				v2.push_back({{1},x});
			(pre+=ans)%=mod;
			swap(v1,v2);
		}
		cout<<ans<<'\n';
	}
	return 0;
}