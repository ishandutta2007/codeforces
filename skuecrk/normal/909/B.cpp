#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100
int a[MN*MN+5],an;
int main()
{
	int n=read(),i,j,k,v;
	for(i=0;i<=n;++i)for(j=0;j<=i;++j)
	{
		for(k=1,v=0;k<=an;++k)if(a[k]<=j&&(!v||a[k]>a[v]))v=k;
		if(!v)a[++an]=i;else a[v]=i;
	}
	printf("%d",an);
}