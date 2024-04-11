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
int n,m,sum,cnt,a[1000001];
std::vector<int> v,ans;
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<m;i++)
	{
		a[i]=read();
		sum+=a[i];
		v.push_back(sum%n);
	}
	a[m]=read();
	cout<<(sum+a[m]+n-1)/n<<'\n';
	v.push_back(n);
	v.push_back(0);
	sort(ALL(v));
	for(int i=1;i<=m;i++)
		ans.push_back(v[i]-v[i-1]);
	for(int i:ans)
		cout<<i<<" ";
	cout<<'\n';
	for(int i=1;i<=m;i++)
	{
		while(a[i]>0)
		{
			cout<<i<<" ";
			a[i]-=ans[cnt++];
			if(cnt==m)
			{
				puts("");
				cnt=0;
			}
		}
	}
	if(!cnt)
		return 0;
	for(;cnt!=m;cnt++)
		cout<<"1 ";
	return 0;
}