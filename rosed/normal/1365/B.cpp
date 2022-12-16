#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) (i&(-i))
	inline int read()
	{
		int x=0;char f=1,ch;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=510;
	int haku;
	int n,s0,s1;
	int a[N],b[N];
	priority_queue<int> q;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();s0=s1=0;
			for(int i=1;i<=n;++i) a[i]=read();
			for(int i=1;i<=n;++i) b[i]=read(),s0|=(b[i]==0),s1|=(b[i]==1);
			if(s0&&s1)
			{
				puts("Yes");
				continue;
			}
			else
			{
				bool flag=0;
				for(int i=2;i<=n;++i)
					flag|=(a[i]<a[i-1]);
				puts(flag?"No":"Yes");
			}
		}
	}
}
signed main()
{
	red::main();
	return 0;
}