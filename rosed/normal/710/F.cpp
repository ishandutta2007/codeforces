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
	const int N=3e5+10,p=1e9+9;
	int Q;
	char s[N];
	struct ACM
	{
		int son[N][26],fail[N],num[N],tot[N],vis[N][26];
		int rt[N],top,cnt,siz[N];
		inline int merge(int x,int y)
		{
			if(!x||!y) return x|y;
			tot[x]+=tot[y];
			for(int i=0;i<26;++i) son[x][i]=merge(son[x][i],son[y][i]);
			return x;
		}
		inline void getfail(int rt)
		{
			queue<int> q;
			for(int i=0;i<26;++i)
			{
				if(son[rt][i]) vis[rt][i]=son[rt][i],fail[son[rt][i]]=rt,q.push(vis[rt][i]);
				else vis[rt][i]=rt;
			}
			while(!q.empty())
			{
				int now=q.front();q.pop();
				for(int i=0;i<26;++i)
				{
					if(son[now][i])
					{
						vis[now][i]=son[now][i],fail[son[now][i]]=vis[fail[now]][i];
						q.push(vis[now][i]);
					}
					else vis[now][i]=vis[fail[now]][i];
				}
				num[now]=tot[now]+num[fail[now]];
			}
		}
		inline void insert(char *s)
		{
			rt[++top]=++cnt,siz[top]=1;
			int now=rt[top];
			for(int i=1,len=strlen(s+1);i<=len;++i)
			{
				int c=s[i]-'a';
				if(!son[now][c]) son[now][c]=++cnt;
				now=son[now][c];
			}
			tot[now]=1;
			while(siz[top]==siz[top-1]) --top,rt[top]=merge(rt[top],rt[top+1]),siz[top]+=siz[top+1];
			getfail(rt[top]);
		}
		inline int query(char *s)
		{
			int ret=0,len=strlen(s+1);
			for(int i=1;i<=top;++i)
			{
				int now=rt[i];
				for(int j=1;j<=len;++j)
				{
					now=vis[now][s[j]-'a'];
					ret+=num[now];
				}
			}
			return ret;
		}
	}A,B;
	inline void main()
	{
		Q=read();
		for(int opt,i=1;i<=Q;++i)
		{
			opt=read();scanf("%s",s+1);
			if(opt==1) A.insert(s);
			if(opt==2) B.insert(s);
			if(opt==3) printf("%lld\n",A.query(s)-B.query(s));
			fflush(stdout);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}