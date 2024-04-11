#include <stdio.h>
#include <string.h> 
#include <queue>
#include <algorithm>
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
struct Q{
	int a,b;
	bool operator<(const Q &bb)const
	{
		return b<bb.b;
	}
}a[200005],b[200005];
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
		int n=read(),m=read();//minn=0x3f3f3f3f3f3f3f3fll,pos=-1;
		for(int i=0;i<m;i++)a[i].a=read(),a[i].b=read();
		std::sort(a,a+m);
		int i=0;
        if(m&1){puts("NO");continue;}
        while(i<m)
        {
            if(a[i].b==a[i+1].b){i+=2;continue;}
            if(i+2<m)
            {
                if(a[i+1].b==a[i+2].b){puts("NO");goto ng;}
                if((a[i+1].b+a[i].b+a[i+1].a+a[i].a)&1)
                {
                    i+=2;
                    continue;
                }
                puts("NO");goto ng;
            }
            else
            {
                if((a[i+1].b+a[i].b+a[i+1].a+a[i].a)&1)
                {
                    i+=2;
                    continue;
                }
                puts("NO");goto ng;
            }
        }
        puts("YES");
        ng:;
	}
}