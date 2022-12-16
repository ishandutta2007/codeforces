#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define y1 qwq 
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=3e5+10,inf=1<<30;
	int haku,n,m,sum;
	int pos,minn;
	struct node
	{
		int x,y;
		inline bool operator < (const node &t) const
		{
			return y-x>t.y-t.x;
		}
	}a[N<<1];
	priority_queue<node> q;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();sum=0;
			while(!q.empty()) q.pop();
			for(int i=1;i<=n;++i)
			{
				a[i].x=read(),a[i].y=read();
			}
			a[0]=a[n];
			for(int i=1;i<=n;++i) 
			{
				q.push((node){max(0ll,a[i].x-a[i-1].y),a[i].x});
				sum+=max(0ll,a[i].x-a[i-1].y);
			}
			node t=q.top();
			sum=sum-t.x+t.y;
			printf("%lld\n",sum);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}