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
	const int N=2e5+10,p=998244353;
	int haku,n,a,b,sum;
	int c[30],s[N];
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),a=read(),b=read();
			sum=0;
			memset(c,0,sizeof(c));
			for(int i=1;i<=n;++i)
			{
				int j=i-a;
				if(j>=1)
				{
					if(!--c[s[j]]) --sum;
				}
				int t=0;
				if(sum==b) while(!c[t]) ++t;
				if(sum<b) while(c[t]) ++t;
				if(!c[t]) ++sum;
				++c[t];
				s[i]=t;
				cout<<(char)(t+'a');
			}
			puts("");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}