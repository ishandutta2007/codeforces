#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10,mod=998244353;
	int T,n,sum,zero=10;
	int a[N];
	map<int,int> q;
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();sum=0;q.clear();
			for(int x,i=1;i<=n;++i)
			{
				x=read();x=abs(x); 
				if(!x)
				{
					if(!q[x]) ++sum;
					q[x]=1;
				}
				else
				{
					if(q[x]<=1)
					{
					 ++sum;
					}
					++q[x];
				}
				
			}
			printf("%lld\n",sum);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
1
3
1 2 3

*/