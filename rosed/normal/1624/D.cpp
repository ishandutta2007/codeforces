#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	inline int read()
	{
		int x=0;char f=0,ch;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=5e5+10,mod=998244353;
	int T,n,m,minn,tot,ret;
	char s[N];
	int num[50];
	priority_queue<int,vector<int>,greater<int> > q;
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read(),m=read();minn=n;ret=0;
			for(int i=1;i<=m;++i) q.push(0);
			for(int i=0;i<26;++i) num[i]=0;
			cin>>(s+1);
			for(int i=1;i<=n;++i)
			{
				++num[(int)(s[i]-'a')];
			}
			tot=n;
			for(int i=0;i<26;++i)
			{
				while(num[i]>=2)
				{
					if(tot>=m) ret=max(q.top()+1,ret);
					int now=q.top();
					q.pop();
					q.push(now+2);
					num[i]-=2;tot-=2;
					if(tot>=m) ret=max(q.top()+1,ret);
				}
			}
			while(!q.empty())
			{
				int now=q.top();
				q.pop();
				if(tot>0) --tot,++now;
				minn=min(minn,now); 
			}
			printf("%lld\n",max(ret,minn));
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
6 2
bfvfbv

*/