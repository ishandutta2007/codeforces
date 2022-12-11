#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
int a[MN+5];
void solve(int n)
{
	for(int i=20,x;i;--i)if(n&(1<<i))
	{
		x=((1<<i+1)-1)^n;
		if(x>1)solve(x-1);
		while(n>=x)printf("%d ",n--);
		return;
	}
}
int main()
{
	int n=read(),i;
	if(n&1)puts("NO");
	else puts("YES"),solve(n),puts("");
	if(n<6||n==(n&-n))puts("NO");
	else
	{
		puts("YES");
		a[1]=3;a[2]=6;a[3]=2;a[4]=5;a[5]=1;a[6]=4;
		for(i=7;i<=n;++i)
			if(i==(i&-i))a[i]=i+1,a[i+1]=i,++i;
			else a[i]=a[i&-i],a[i&-i]=i;
		for(i=1;i<=n;++i)printf("%d ",a[i]);
	}
}