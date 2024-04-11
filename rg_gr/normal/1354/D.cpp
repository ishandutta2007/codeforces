#include <stdio.h>
#include <stdlib.h>
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
int n=1;
int a[2000005];
inline int lowbit(int x)
{
	return x&(-x);
}
inline void add(int aa,int x)
{
	while(aa<=n)a[aa]+=x,aa+=lowbit(aa);
}
inline int query(int aa)
{
	int ans=0;
	while(aa)ans+=a[aa],aa-=lowbit(aa);
	return ans;
}
inline void del(int k)
{
	int ans=0;int m,q;
	for(int i=n;ans+i<=n&&i;i>>=1)
		if(query(ans+i)<k)ans+=i;
	ans++;
	//	for(int i=1;i<=n;i++)printf("%d ",query(i));puts("");
	//printf("Find %d\n",ans);
	add(ans,-1);
}
inline void del()
{
	int L=1,R=n,ans=0;
	while(L<=R)
	{
		int m=L+R>>1;
		if(query(m))ans=m,R=m-1;
		else L=m+1;
	}
	printf("%d\n",ans);
}
int main()
{
	int m=read(),q=read(),x;
	while(n<m)n<<=1;int u=0;
	for(int i=1;i<=m+q;i++)
	{
		x=read();
		if(x>0)add(x,1),u++;
		else del(-x),u--;
	}
	if(u)
	{
		//for(int i=1;i<=n;i++)printf("%d ",query(i));puts("");
		del();
	}
	else puts("0");
}