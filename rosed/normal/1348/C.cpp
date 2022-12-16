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
	int haku,n,m;
	char s[N];
	int sum[27];
	int ans[N],cnt,tot;
	inline void main()
	{
		haku=read();
		while(haku--)
		{
			n=read(),m=read();
			scanf("%s",s+1);
			memset(sum,0,sizeof(sum));
			for(int i=1;i<=n;++i) ++sum[s[i]-'a'+1];
			cnt=tot=0;
			bool flag=0;
			for(int i=1;i<=26;++i)
			{
				if(!sum[i]) continue;
				if(tot+sum[i]<m)
				{
					tot+=sum[i];
					ans[1]=i;
					flag=1;
				}
				else
				{
					ans[1]=i;
					sum[i]-=m-tot;
					putchar(ans[1]+'a'-1);
					if(flag) break;
					int pos=0;
					for(int j=i;j<=26;++j)
					{
						if(sum[j]) ++cnt,pos=j;
					}
					if(cnt==1)
					{

						for(int j=1;j<=(sum[pos]-1)/m+1;++j) putchar(pos+'a'-1);
					}
					else
					{
						for(int j=i;j<=26;++j)
						{
							while(sum[j]--) putchar(j+'a'-1);
						}
					}
					break;
				}
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
/* 
1
8 3
aaaaabb

*/