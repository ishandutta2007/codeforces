#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
const int N=5e5+10,inf=2e9;
int n,m;
int a[N];
bool vis[27];
string s;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int qwq;
	cin>>qwq;
	while(qwq--)
	{

		cin>>n;
		cin>>s;
		int sum=0;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;++i)
		{
			int c=s[i]-'A';
			if(!vis[c]) ++sum,vis[c]=1;
			++sum;
		}
		cout<<sum<<'\n';
	}
	return 0;
}