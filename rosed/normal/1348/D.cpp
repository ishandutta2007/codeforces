#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=2e5+10,p=998244353;
	int haku,n;
	int day,sum,num;
	int ans[N];
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read();
			day=0;
			while((1<<(day+1))-1<n) ++day;
			printf("%lld\n",day);
			sum=num=1;
			for(int i=1;i<=day;++i)
			{
				int l=0,r=num,ret=0;
				while(l<=r)
				{
					int mid=(l+r)>>1;
					if((num+mid)*(day-i+1)+sum<=n) ret=mid,l=mid+1;
					else r=mid-1;
				}
				num+=ret;
				sum+=num;
				ans[i]=ret;
			}
			for(int i=1;i<=day;++i) printf("%lld ",ans[i]);
			puts("");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
3
9
11
2

*/