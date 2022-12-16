#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
	const int N=3e5+10,mod=998244353;
	char s[N];
	int s1,s2;
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		int T;cin>>T;
		while(T--)
		{
			cin>>(s+1);
			int n=strlen(s+1);
			s1=s2=0;
			for(int i=1;i<=n;++i)
			{
				if(s[i]=='0') ++s1;
				else ++s2;
			}
			if(s1==s2) --s1;
			cout<<min(s1,s2)<<'\n';
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