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
	const int N=5e5+10,mod=1e9+7;
	int n,m,k;
	
	int a[110][110];
	int f[110][110][910],g[110][110][910];
	int st[N],top;
	string s;
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		cin>>n>>m>>k;
		++k;
		for(int i=1;i<=n;++i)
		{
			cin>>s;
			for(int j=1;j<=m;++j)
			{
				a[i][j]=s[j-1]-'0';
			}
		}
		for(int j=1;j<=m;++j) f[n][j][a[n][j]]=1;
		for(int i=n-1;i;--i)
		{
			for(int j=1;j<=m;++j)
			{
				for(int k=a[i][j];k<=900;++k)
				{
					if(f[i+1][j-1][k-a[i][j]]) f[i][j][k]=1,g[i][j][k]=j-1;
					if(f[i+1][j+1][k-a[i][j]]) f[i][j][k]=1,g[i][j][k]=j+1;
				}
			}
		}
		int ans=-1,pos=0;
		for(int p=900;p>=0;--p)
		{
			if(p%(k)) continue;
			for(int j=1;j<=m;++j)
			{
				if(f[1][j][p])
				{
					ans=p;
					pos=j;
					break;
				}
			}
			if(~ans) break;
		}
		cout<<ans<<'\n';
		if(ans==-1) return;
		
		for(int i=1;i<n;++i)
		{
			int t=g[i][pos][ans];
			ans-=a[i][pos];
			if(t<pos) st[++top]=-1;
			else st[++top]=1;
			pos=t;
		}
		cout<<pos<<'\n';
		
		for(int i=top;i;--i)
		{
			cout<<"LR"[st[i]==-1];
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*

kkkljkk
*/