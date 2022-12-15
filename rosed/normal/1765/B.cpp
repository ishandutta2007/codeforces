#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
#define lowbit(i) ((i)&(-i))
void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	bool flag=1;
	int opt=0;
	reverse(s.begin(),s.end());
	while(!s.empty())
	{
		if(opt==0) s.pop_back();
		else
		{
			if(s.size()<2)
			{
				cout<<"NO\n";
				return;
			}
			char t1=s.back();
			s.pop_back();
			char t2=s.back();
			s.pop_back();
			if(t1!=t2)
			{
				cout<<"NO\n";
				return;
			}
		}
		opt^=1;
	}
	cout<<"YES\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--) solve();
	return 0;
}