#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
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
	const int N=2e5+10,inf=1e9+7;
	int n,m,k,s,now,ret;
	int c[N],num;
	int f[N],cnt[N];
	int l[N],r[N],id[N]; 
	vector<int> d[N];
	inline void main()
	{
		n=read(),m=read(),k=read();s=1<<k;
		for(int i=1;i<s;++i) cnt[i]=cnt[i>>1]+(i&1);
		for(int i=1;i<=n;++i)
		{
			l[i]=read(),r[i]=read()+1;
			c[++num]=l[i],c[++num]=r[i];
		}
		c[++num]=m;c[++num]=1;
		sort(c+1,c+num+1);num=unique(c+1,c+num+1)-c-1;
		for(int i=1;i<=n;++i)
		{
			l[i]=lower_bound(c+1,c+num+1,l[i])-c;
			r[i]=lower_bound(c+1,c+num+1,r[i])-c;
			for(int j=l[i];j<r[i];++j) d[j].push_back(i);
		}
		memset(f,0xcf,sizeof(f));f[0]=0;
		for(int i=1;i<num;++i)
		{
			for(int j=0;j<k;++j)
				if(id[j]&&r[id[j]]<=i) now^=1<<j,id[j]=0;
			for(int j=0;j<s;++j)
				if((j|now)!=now) f[j&now]=max(f[j&now],f[j]),f[j]=-inf;
			for(int j=0;j<d[i].size();++j) if(l[d[i][j]]==i)
			{
				for(int p=0;p<k;++p) if(!id[p])
				{
					for(int l=s-1;~l;--l)
					{
						f[l|1<<p]=f[l];
					}
					id[p]=d[i][j],now|=1<<p;break;
				}
			}
			for(int j=0;j<s;++j)
				f[j]+=(cnt[j]&1)*(c[i+1]-c[i]);
		}
		for(int i=0;i<s;++i) ret=max(ret,f[i]);
		printf("%lld\n",ret);
	}
}
signed main()
{
	red::main();
	return 0;
}