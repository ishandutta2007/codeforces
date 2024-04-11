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
	const int N=3e5+10;
	int T,n,tot;
	struct node
	{
		int x,id;
		inline bool operator < (const node &t) const
		{
			return x<t.x;
		}
	}a[N];
	priority_queue<node> q; 
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();tot=0;
			while(!q.empty()) q.pop();
			for(int x,i=1;i<=n;++i) 
			{
				x=read();
				if(x) q.push((node){x,i});
			}
			while(q.size()>1)
			{
				node x=q.top();
				q.pop();
				node y=q.top();
				q.pop();
				a[++tot]=(node){x.id,y.id};
				if(x.x>1) q.push((node){x.x-1,x.id});
				if(y.x>1) q.push((node){y.x-1,y.id});
			}
			printf("%lld\n",tot);
			for(int i=1;i<=tot;++i) printf("%lld %lld\n",a[i].x,a[i].id); 
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
4 9 2
*.*.*...*
.*.*...*.
..*.*.*..
.....*...

*/