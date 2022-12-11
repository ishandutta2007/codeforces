#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 1000000
int u[MN+5],p[MN+5],pn,f[MN+5];
int main()
{
	int x,i,j;
	scanf("%d",&x);
	for(i=2;i<=MN;++i)
	{
		if(!u[i])u[i]=p[++pn]=i;
		for(j=1;i*p[j]<=MN;++j)if(u[i*p[j]]=p[j],i%p[j]==0)break;
		if(u[i]==i){f[i]=i;continue;}
		for(f[i]=j=i;j>1;j/=u[j])f[i]=min(f[i],i-u[j]+1);
	}
	if(u[x]==x)return 0*printf("%d",x);
	for(f[0]=x,i=f[x];i<=x;++i)f[0]=min(f[0],f[i]);
	printf("%d",f[0]);
}