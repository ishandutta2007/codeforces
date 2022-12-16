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
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=3e5+10,inf=0x3f3f3f3f;
	int n,m,ret,tmp,tot,rt[N];
	int ans[N<<5],son[N<<5][2];
	inline void update(int pos,int l,int r,int &p,int k)
	{
		if(!p) p=++tot;
		if(l==r)
		{
			ans[p]=max(ans[p],k);
			return;
		}
		if(pos<=mid) update(pos,l,mid,son[p][0],k);
		else update(pos,mid+1,r,son[p][1],k);
		ans[p]=max(ans[son[p][0]],ans[son[p][1]]);
	}
	inline int query(int tl,int tr,int l,int r,int p)
	{
		if(!p) return 0;
		if(tl<=l&&r<=tr) return ans[p];
		int ret=0;
		if(tl<=mid) ret=max(ret,query(tl,tr,l,mid,son[p][0]));
		if(tr>mid) ret=max(ret,query(tl,tr,mid+1,r,son[p][1]));
		return ret;
	}
	inline void main()
	{
		n=read(),m=read();
		for(int x,y,z,i=1;i<=m;++i)
		{
			x=read(),y=read(),z=read();
			tmp=query(1,z,1,100000,rt[x])+1;
			ret=max(tmp,ret);
			update(z+1,1,100000,rt[y],tmp);
		}
		printf("%lld\n",ret);
	}
}
signed main()
{
	red::main();
	return 0;
}