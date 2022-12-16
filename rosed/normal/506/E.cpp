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
	const int N=3e5+10,p=1e4+7;
	char s[2000];
	int n,m,up;
	int f[210][210][210],g[210];
	struct matrix 
	{
		int a[310][310];
		int * operator [] (const int &t){return a[t];}
		matrix(){memset(a,0,sizeof(a));}
		inline matrix operator * (const matrix &t) const
		{
			matrix ret;
			for(int i=0;i<=up;++i)
			{
				for(int j=i;j<=up;++j)
				{
					for(int k=1;k<=j;++k)
					{
						(ret.a[i][j]+=a[i][k]*t.a[k][j]%p)%=p;
					}
				}
			}
			return ret;
		}
		inline matrix operator ^ (int k) const
		{
			matrix ret,x=*this;
			for(int i=0;i<=up;++i) ret.a[i][i]=1;
			while(k)
			{
				if(k&1) ret=ret*x;
				x=x*x;
				k>>=1;
			}
			return ret;
		}
	}S,T;
	inline void main()
	{
		scanf("%s",s);n=strlen(s);
		m=read();
		f[0][n-1][0]=1;
		for(int i=0;i<n;++i)
		{
			for(int j=n-1;j>=i;--j)
			{
				if(s[i]==s[j])
				{
					for(int k=0;k<i+n-j;++k)
					{
						if(i+1<j) (f[i+1][j-1][k]+=f[i][j][k])%=p;
						else g[k]=(g[k]+f[i][j][k])%p;
					}
				}
				else
				{
					for(int k=0;k<i+n-j;++k)
					{
						(f[i+1][j][k+1]+=f[i][j][k])%=p;
						(f[i][j-1][k+1]+=f[i][j][k])%=p;
					}
				}
			}
		}
		up=n+(n+1)/2+1;
		S[0][1]=1,S[0][up-(n+1)/2]=g[0],T[up][up]=26;
		for(int i=1;i<=n;++i)
		{
			T[i][i]=24,T[i][up-(n-i+1)/2]=g[i];
			if(i!=n) T[i][i+1]=1;
		}
		for(int i=n+1;i<up;++i) T[i][i+1]=1,T[i][i]=25;
		if((n+m)&1)
		{
			T=T^((n+m+1)>>1);
			S=S*T;
			int ans=S[0][up];
			memset(S.a,0,sizeof(S.a));
			memset(T.a,0,sizeof(T.a));
			memset(g,0,sizeof(g));
			for(int i=0;i<n-1;++i) if(s[i]==s[i+1])
			{
				for(int k=0;k<=n;++k)
				{
					(g[k]+=f[i][i+1][k])%=p;
				}
			}
			S[0][1]=1,S[0][up-(n+1)/2]=g[0];
			for(int i=1;i<=n;++i)
			{
				T[i][i]=24,T[i][up-(n-i+1)/2]=g[i];
				if(i!=n) T[i][i+1]=1;
			}
			for(int i=n+1;i<up;++i) T[i][i+1]=1,T[i][i]=25;
			T=T^((n+m+1)>>1);
			S=S*T;
			printf("%d\n",(ans-S[0][up]+p)%p);
		}
		else
		{
			T=T^((n+m+1)>>1);
			S=S*T;
			printf("%d\n",S[0][up]);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}