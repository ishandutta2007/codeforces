#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	s="#"+s;
	vector<int> pre(10,0);
	vector sum(10,vector<int>(n+1));
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		int c=s[i]-'0';
		pre[c]=i;
		vector<int> tmp;
		for(int k=0;k<10;++k)
		{
			if(pre[k]) tmp.emplace_back(pre[k]);
			sum[k][i]=sum[k][i-1];
		}
		++sum[c][i];
		sort(tmp.begin(),tmp.end());
		tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
		int tot=tmp.size();
		for(int j=0;j<tot;++j)
		{
			int y=tmp[j];
			// cout<<j<<' '<<y<<' '<<tot<<"!!"<<endl;
			int pre=0;
			if(j>0) pre=tmp[j-1];
			while(y>pre)
			{
				int maxn=0;
				for(int k=0;k<10;++k)
				{
					maxn=max(maxn,sum[k][i]-sum[k][y-1]);
				}
				if(maxn>tot-j) break;
				++ans;
				--y;
			}
		}
		// cout<<ans<<"!!"<<endl;
	}
	cout<<ans<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--) solve();
	return 0;
}