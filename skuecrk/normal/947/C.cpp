#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 300000
struct node{int c[2],s;}t[MN*40+5];
int rt,tn,a[MN+5];
void ins(int&k,int l,int x)
{
	++t[k=k?k:++tn].s;
	if(l<0)return;
	ins(t[k].c[(x>>l)&1],l-1,x);
}
int query(int k,int l,int x)
{
	--t[k].s;
	if(l<0)return 0;
	if(t[t[k].c[(x>>l)&1]].s)return query(t[k].c[(x>>l)&1],l-1,x);
	return query(t[k].c[((x>>l)&1)^1],l-1,x)+(1<<l);
}
int main()
{
	int n=read(),i;
	for(i=1;i<=n;++i)a[i]=read();
	for(i=1;i<=n;++i)ins(rt,29,read());
	for(i=1;i<=n;++i)printf("%d ",query(rt,29,a[i]));
}