#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
	const int N=1e5+10,mod=998244353;
	int n,m;
	char s[N];
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		int T;cin>>T;
		while(T--)
		{
			cin>>n;
			cin>>(s+1);
			int s1=0,s2=0;
			for(int i=1;i<=n;++i)
			{
				s1+=(s[i]=='0');
				s2+=(s[i]=='1');
			}
			if(s1>=2||s2>=2) cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
}
signed main()
{
	red::main();
	return 0;	
}
/*
5 7
1 2 3 4 5
1 1 5
2 1 5

3 1 2 1
1 1 4
4 1 3 2
1 1 4
2 2 3

*/