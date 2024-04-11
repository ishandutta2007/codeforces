#include<bits/stdc++.h>
using namespace std;
namespace red{
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1) 
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=2e5+10;
	char s[N];
	int a[N][26];
	int n,m;
	inline void main()
	{
		scanf("%s",s+1);n=strlen(s+1);
		for(int i=1;i<=n;++i)
		{
			++a[i][s[i]-'a'];
			for(int j=0;j<26;++j) a[i][j]+=a[i-1][j];
		}
		m=read();
		for(int l,r,i=1;i<=m;++i)
		{
			l=read(),r=read();
			if(l==r)
			{
				puts("Yes");
				continue;
			}
			int sum=0;
			for(int j=0;j<26;++j)
			{
				if(a[r][j]-a[l-1][j]>0) ++sum;
			}
			if(sum>2||s[l]!=s[r]) puts("Yes");
			else puts("No");
		}
	}
}
signed main()
{

	red::main();
	return 0;
}