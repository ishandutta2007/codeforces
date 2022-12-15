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
	string s;
	cin>>s;
	int k;cin>>k;
	int n=s.length();
	s="#"+s;
	vector nxt(n+1,vector<int>(10,n+1));
	for(int i=n-1;i>=0;--i)
	{
		for(int c=0;c<10;++c) nxt[i][c]=nxt[i+1][c];
		nxt[i][s[i+1]-'0']=i+1;
	}
	k=n-k;
	int pos=0;
	while(k)
	{
		int st=(pos==0?1:0);
		for(int c=st;c<=9;++c)
		{
			if(n-nxt[pos][c]+1>=k)
			{
				pos=nxt[pos][c];
				cout<<c;
				--k;
				break;
			}
		}
	}
	cout<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1; cin>>T;
	while(T--) solve();
	return 0;
}