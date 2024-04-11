#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10,inf=2e9;
	int n,m;
	int a[N];
	char s[N];
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{	
			cin>>(s+1);
			n=strlen(s+1);
			char ch='9';
			if(n==2) ch=s[2];
			else
			{
				for(int i=1;i<=n;++i)
				{
					if(s[i]-'0'<ch-'0') ch=s[i];
				}
			}
			cout<<ch<<'\n';
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
212
*/