#include <stdio.h>
#include <string.h> 
#include <queue>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
struct Q{
	int a,b,i;
	bool operator<(const Q &bb)const
	{
		return b<bb.b;
	}
}a[200005];
int s[200005];
/*inline int lowbit(int a)
{
	return a&(-a);
}
inline void add(int p,int a)
{
	while(p<=n)s[p]+=a,p+=lowbit(p);
}
inline int query(int p)
{
	int res=0;
	while(p)res+=s[p],p-=lowbit(p);
	return res;
}*/
int ans[200005];
signed main()
{
    int T=read();
	while(T--)
	{
		int n=read(),minn=0x3f3f3f3f3f3f3f3fll,pos=-1;
		for(int i=0;i<n;i++)a[i].a=read(),a[i].b=read(),a[i].i=i;
		for(int i=0;i<n;i++)
			if(a[i].a>a[i].b)a[i].a^=a[i].b^=a[i].a^=a[i].b;
		std::sort(a,a+n);
		int cur=0;
		for(int i=0;i<n;i++)
		{
			if(i&&a[i].b!=a[i-1].b)
			{
				for(int j=cur;j<i;j++)
				{
					if(minn>a[j].a)minn=a[j].a,pos=j;
				}
				cur=i;
			}
			int p=a[i].a;
			if(p>minn)ans[a[i].i]=a[pos].i;
			else ans[a[i].i]=-2;
		}
		for(int i=0;i<n;i++)printf("%lld ",ans[i]+1);
		puts("");
	}
}