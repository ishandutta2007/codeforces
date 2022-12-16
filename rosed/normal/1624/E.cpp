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
	int T,n,m;
	struct node
	{
		int l,r,id;
	}st[N],f[N];
	int top;
	map<int,node> q2,q3;
	char s[N];
	int g[N];
	inline void main()
	{
		T=read();
		while(T--)
		{
			m=read(),n=read();q2.clear(),q3.clear();
			for(int t2,t3,j=1;j<=m;++j)
			{
				cin>>(s+1);
				for(int i=2;i<=n;++i)
				{
					if(i>=2)
					{
						g[i]=i-2;
						t2=(s[i-1]-'0')*10+s[i]-'0';
						q2[t2]=(node){i-1,i,j};
					}
					if(i>=3)
					{
						g[i]=i-3;
						t3=(s[i-2]-'0')*100+(s[i-1]-'0')*10+s[i]-'0';
						q3[t3]=(node){i-2,i,j};
					}
				}
			}
			cin>>(s+1);
			f[0]=(node){0,0,0};
			for(int t2,t3,i=1;i<=n;++i)
			{
				f[i]=(node){0,0,-1};
				if(i>=2)
				{
					t2=(s[i-1]-'0')*10+s[i]-'0';
					if((f[i-2].id!=-1)&&q2[t2].id!=0)
					{
						g[i]=i-2;
						f[i]=q2[t2];
					}
				}
				if(i>=3)
				{
					t3=(s[i-2]-'0')*100+(s[i-1]-'0')*10+s[i]-'0';
					if((f[i-3].id!=-1)&&q3[t3].id!=0)
					{
						g[i]=i-3;
						f[i]=q3[t3];
					}
				}
			}
			if(f[n].id==-1) puts("-1");
			else
			{
				int now=n;top=0;
				while(now)
				{
					st[++top]=f[now];
					now=g[now];
				}
				printf("%lld\n",top);
				while(top) {printf("%lld %lld %lld\n",st[top].l,st[top].r,st[top].id);top--;}
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


*/