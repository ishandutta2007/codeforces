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
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int qwq;
	cin>>qwq;
	while(qwq--)
	{
		string s;cin>>s;
		int n=s.length();
		for(int i=0;i<3;++i)
		{
			if(s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
		}
		if(s=="yes") cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}