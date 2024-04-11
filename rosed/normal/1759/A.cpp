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
	string s;
	cin>>s;
	int n=s.length();
	bool flag=1;
	for(int i=0;i<n;++i)
	{
		if(s[i]!='Y'&&s[i]!='e'&&s[i]!='s') flag=0;
		if(i>0)
		{
			if(s[i]=='Y'&&s[i-1]!='s') flag=0;
			if(s[i]=='e'&&s[i-1]!='Y') flag=0;
			if(s[i]=='s'&&s[i-1]!='e') flag=0;
		}
	}
	if(flag) cout<<"YES\n";
	else cout<<"NO\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--) solve();
	return 0;
}