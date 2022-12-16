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
		for(int i=1;i<=n;++i) cin>>a[i];
		for(int i=1;i<=n;++i)
		{
			cin>>m;
			cin>>s;
			for(int j=0;j<m;++j)
			{
				if(s[j]=='D') a[i]=(a[i]+1)%10;
				else a[i]=(a[i]-1+10)%10;
			}
			cout<<a[i]<<" \n"[i==n];
		}
	}
	return 0;
}