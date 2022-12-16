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
	int T,n,tmp;
	int a[4],b[4]; 
	bool flag;
	inline void main()
	{
		T=read();
		while(T--)
		{
			flag=0;
			a[1]=read(),a[2]=read(),a[3]=read();
			// 1 2
			tmp=a[2]+a[2]-a[1];
			if(tmp%a[3]==0&&tmp>0) flag=1;
			// 1 3
			if((a[3]-a[1])%2==0)
			{
				tmp=a[1]+(a[3]-a[1])/2;
				if(tmp%a[2]==0&&tmp>0) flag=1;
			}
			//2 3
			tmp=a[2]+a[2]-a[3];
			if(tmp%a[1]==0&&tmp>0) flag=1;
			puts(flag?"YES":"NO");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*


*/