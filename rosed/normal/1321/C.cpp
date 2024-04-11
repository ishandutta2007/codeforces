#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
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
	const int N=1e5+10;
	int haku;
	int n,m,ret;
	char s[N];
	inline void main()
	{
		n=read();
		scanf("%s",s+1);
		s[n+1]=0;
		for(int k=25;k;--k)
		{
			while("haku")
			{
				bool flag=0;
				for(int i=1;i<=n;++i)
				{
					if(s[i]-'a'==k)
					{
						if(s[i-1]-'a'==k-1||s[i+1]-'a'==k-1)
						{
							flag=1;
							++ret;
							for(int j=i+1;j<=n;++j) s[j-1]=s[j];
							break;
						}
					}
				}
				if(!flag) break;
				s[n--]=0;
			}
		}
		cout<<ret<<endl;
	}
}
signed main()
{
	red::main();
	return 0;
}
//