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
	const int N=5e5+10;
	int T,n,sum,num;
	int a[N],c[N];
	int tr[N];
	inline void update(int x)
	{
		for(int i=x;i<=num;i+=lowbit(i)) ++tr[i];
	}
	inline int query(int y)
	{
		int ret=0;
		for(int i=y;i;i-=lowbit(i)) ret+=tr[i];
		return ret;
	}
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();sum=num=0;
			for(int i=1;i<=n;++i) tr[i]=0,a[i]=read(),c[++num]=a[i];
			sort(c+1,c+num+1);
			num=unique(c+1,c+num+1)-c-1;
			for(int x,t1,t2,i=1;i<=n;++i)
			{
				x=lower_bound(c+1,c+num+1,a[i])-c;
				t1=query(x-1);
				t2=i-1-query(x);
				sum+=min(t1,t2);
				update(x);
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
4 9 2
*.*.*...*
.*.*...*.
..*.*.*..
.....*...

*/