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
	const int N=1e5+10;
	int T,n; 
	int a[N],c[N],pos[N],num;
	struct node
	{
		int l,r,d;
	}e[N];
	int tot;
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();num=tot=0;
			for(int i=1;i<=n;++i) a[i]=read(),c[++num]=a[i];
			sort(c+1,c+num+1);
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=n;++j)
				{
					if(a[i]==c[j])
					{
						a[i]=j;
						c[j]=1e9+10;
						break;
					}
				}
			}
			
			for(int pos,i=1;i<=n;++i)
			{
			//	cout<<i<<' '<<a[i]<<"!!"<<endl;
				pos=i;
				for(int j=i;j<=n;++j)
				{
					if(a[j]==i){pos=j;break;}
				}
				if(pos==i) continue;
				e[++tot].l=i,e[tot].r=pos,e[tot].d=pos-i;
				for(int j=pos;j>i;--j) a[j]=a[j-1];
				a[i]=i;
			}
			printf("%lld\n",tot);
			for(int i=1;i<=tot;++i)
			{
				printf("%lld %lld %lld\n",e[i].l,e[i].r,e[i].d);
			}
		}
	}
}
signed main()
{
	red::main();
	return 0;
}