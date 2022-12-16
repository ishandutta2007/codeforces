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
	const int N=3e5+10;
	int T,n,ans;
	char a[N],b[N];
	int s00,s01,s10,s11;
	int s0,s1,s2;
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();s0=s1=s2=0;
			s00=s01=s10=s11=0;
			ans=1e9+7;
			cin>>(a+1)>>(b+1);
			for(int i=1;i<=n;++i)
			{
				if(a[i]==b[i]) ++s0;
				else ++s1;
				if(a[i]=='0'&&b[i]=='0') ++s2;
				if(a[i]=='0'&&b[i]=='1') ++s01;
				if(a[i]=='1'&&b[i]=='0') ++s10;
				if(a[i]=='0'&&b[i]=='0') ++s00;
				if(a[i]=='1'&&b[i]=='1') ++s11;
			}
			if(!s1) puts("0");
			else
			{
				if(s11&&s0%2==1&&s00<=s11&&s00>=s11-1) ans=min(ans,s0);
				if(s10&&s1%2==0&&s01<=s10&&s01>=s10-1) ans=min(ans,s1);
				if(ans!=1e9+7) printf("%lld\n",ans);
				else puts("-1");
			}
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*

01--2> 11
1
9
100010111
101101100

1
4
1000
0111

1111
0111
0100
0111

1
3
010
100

111
100

101
100

011
100

100
100

1
3
00000
01110

11111
01110

00100
01110

11011
01110

01100
01110

10011
01110

01110
01110

3
000
101

111
101
100
101
011
101
101
101
*/