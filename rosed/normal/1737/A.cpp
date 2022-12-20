#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
const int inf=1e15;
void solve()
{
	int n,m;
	cin>>n>>m;
	string s;cin>>s;
	vector<int> cnt(26);
	for(char ch:s)
	{
		++cnt[ch-'a'];
	}
	for(int i=1;i<=m;++i)
	{
		int ch=0;
		for(int c=0;c<min(n/m,26ll);++c)
		{
			if(cnt[c]>=i) ch=c+1;
			else break;
		}
		cout<<(char)(ch+'a');
	}
	cout<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1;cin>>T;
	while(T--) solve();
	return 0;
}