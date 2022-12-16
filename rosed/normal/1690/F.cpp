#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10,inf=1e9+7;
	int n,m,ans;
	char s[N];
	int p[N];
	bool vis[N];
	char t[N];
	int nxt[N];
	inline void getnxt()
	{
		int t1=0,t2=-1;nxt[0]=-1;
		while(t1<m)
		{
			if(t2==-1||t[t1]==t[t2]) nxt[++t1]=++t2;
			else t2=nxt[t2];
		}
	}
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			cin>>n;
			cin>>(s+1);
			ans=1;
			for(int i=1;i<=n;++i)
			{
				cin>>p[i];
				vis[i]=0;
			}
			for(int i=1;i<=n;++i)
			{
				m=0;
				int now=i;
				while(!vis[now])
				{
					t[m++]=s[now];
					vis[now]=1;
					now=p[now];
				}
				if(!m) continue;
				//t[m]=0;
				//cout<<t<<'\n';
				getnxt();
				int len=m;now=nxt[m];
				while(now>0)
				{
					int tmp=m-now;
					if(m%tmp==0)
					{
						len=tmp;break;
					}
					now=nxt[now];
				}
				ans=ans/__gcd(ans,len)*len;
			}
			cout<<ans<<'\n';
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
5
ababa
2 1 4 5 3

*/