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
	const int N=5e5+10;
	int n,d,m,k;
	char s[N];
	int b[33][2],f[33],vis[500];
	int head[N],cnt;
	struct point
	{
		int nxt,to;
		point(){}
		point(const int &nxt,const int &to):nxt(nxt),to(to){}
	}a[N<<1];
	inline void link(int x,int y)
	{
		a[++cnt]=(point){head[x],y};head[x]=cnt;
	}
	inline int get(int x)
	{
		return x<=n?x+n:x-n;
	}
	inline bool dfs(int now)
	{
		if(vis[get(now)]) return 0;
		vis[now]=1;
		for(int i=head[now];i;i=a[i].nxt)
		{
			int t=a[i].to;
			if(!vis[t]&&!dfs(t)) return 0;
		}
		return 1;
	}
	inline bool check(int o)
	{
		for(int i=1;i<=(n<<1);++i) vis[i]=0;
		for(int i=1;i<=o;++i)
			if(!dfs(i+f[s[i]-'a'+1]*n)) return 0;
		for(int i=o+1;i<=n;++i)
		{
			if(vis[i]) s[i]=b[1][0]+'a'-1;
			else if(vis[i+n]) s[i]=b[1][1]+'a'-1;
			else
			{
				int x=min(b[1][0],b[1][1]),y=max(b[1][0],b[1][1]);
				if(dfs(i+f[x]*n)) s[i]=x+'a'-1;
				else if(dfs(i+f[y]*n)) s[i]=y+'a'-1;
				else return 0;
			}
		}
		return 1;
	}
	inline void main()
	{
		scanf("%s",s+1);k=strlen(s+1);
		map<char,int> p;
		p['V']=0,p['C']=1;
		b[k+1][0]=b[k+1][1]=k+1;
		for(int i=k,t[2]={k+1,k+1};i;--i)
			t[f[i]=p[s[i]]]=i,b[i][0]=t[0],b[i][1]=t[1];
		n=read(),m=read();
		for(int x,y,s1,t1,s2,t2,i=1;i<=m;++i)
		{
			x=read();scanf("%s",s+1);y=strlen(s+1);
			s1=x+p[s[y]]*n,s2=get(s1);
			x=read();scanf("%s",s+1);y=strlen(s+1);
			t1=x+p[s[y]]*n,t2=get(t1);
			link(s1,t1);
			link(t2,s2);
		}
		scanf("%s",s+1);n=strlen(s+1);
		if(check(n)) return(void)printf("%s",s+1);
		else if(b[1][0]==k+1||b[1][1]==k+1) return(void)puts("-1");
		for(int i=n;i;--i)
		{
			int c=s[i]-'a'+2,x=min(b[c][0],b[c][1]),y=max(b[c][0],b[c][1]);
			if(x!=k+1)
			{
				s[i]=x+'a'-1;
				if(check(i)) return(void)printf("%s",s+1); 
			}
			if(y!=k+1)
			{
				s[i]=y+'a'-1;
				if(check(i)) return(void)printf("%s",s+1); 
			}
		}
		puts("-1");
	}
}
signed main()
{
	red::main();
	return 0;
}