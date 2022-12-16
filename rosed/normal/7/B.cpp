#include<bits/stdc++.h>
using namespace std;
namespace red{
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=1e5+10;
	int n,m,id;
	int a[N],b[N];
	int l[N],r[N];
	char s[N];
	inline void alloc(int x)
	{
		int pre=1;
		for(int i=1;i<=m;++i)
		{
			if(b[i]) pre=i+1;
			else
			{
				if(i-pre+1>=x)
				{
					++id;
					for(int j=pre;j<=i;++j) b[j]=id;
					l[id]=pre,r[id]=i;
					printf("%d\n",id); 
					return;
				}
			}
		}
		puts("NULL");
	}
	inline void erase(int x)
	{
		if(x<=0||x>id)
		{
			puts("ILLEGAL_ERASE_ARGUMENT");
			return;
		}
		bool flag=0;
		for(int i=1;i<=m;++i)
		{
			if(b[i]==x)
			{
				flag=1;
				b[i]=0;
			}
		}
		if(!flag) puts("ILLEGAL_ERASE_ARGUMENT");
	}
	inline void get_col(int x,int y,int col)
	{
		for(int i=x;i<=y;++i) b[i]=col;
		if(col) l[col]=x,r[col]=y;
	}
	inline void defragment()
	{
		int pre=1;
		for(int i=1;i<=m;++i)
		{
			if(b[i])
			{
				if(pre==l[b[i]])
				{
					pre=r[b[i]]+1;
					i=r[b[i]];
				}
				else
				{
					int col=b[i],len=r[col]-l[col];
					get_col(l[col],r[col],0);
					get_col(pre,pre+len,col);
					i=r[col];
					pre=r[col]+1;
				}
			}
		}
	}
	inline void main()
	{
		n=read(),m=read();
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s);
			if(s[0]=='a') alloc(read());
			if(s[0]=='e') erase(read());
			if(s[0]=='d') defragment();
		}
	}
}
signed main()
{
	red::main();
	return 0;
}