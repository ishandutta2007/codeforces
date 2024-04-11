#include<stdio.h>
using namespace std;
long father[105];
long n,m;bool q[105][105]={false};
bool zero=true;
long get(long x){if(x==father[x])return x;father[x]=get(father[x]);return father[x];}
void Union(long a,long b){father[get(a)]=get(b);}
bool work(long i,long j)
{
	for(long k=1;k<=m;k++)
	if(q[i][k]&&q[j][k])return true;
	return false;
}
int main()
{
	scanf("%ld%ld",&n,&m);
	for(long i=1;i<=n;i++)
	{
		long k;scanf("%ld",&k);
		if(k!=0)zero=false;
		for(long j=1;j<=k;j++)
		{
			long a;scanf("%ld",&a);
			q[i][a]=true;
		}
	}
	if(zero==true)
	{
		printf("%ld\n",n);
		return 0;
	}
	for(long i=1;i<=n;i++)father[i]=i;
	for(long i=1;i<=n;i++)
	for(long j=i+1;j<=n;j++)
	if(work(i,j))Union(i,j);
	long ans=0;
	for(long i=1;i<=n;i++)if(get(i)==i)ans++;
	printf("%ld\n",ans-1);
	return 0;
}