#include<stdio.h>
#include<cstring>
#include<algorithm>
#define mod2 10007
using namespace std;
typedef unsigned long long ull;
struct jsb
{
	int h1,h2;
	ull y;
}data[1100000];
inline bool cmp(const jsb &a,const jsb &b)
{
	if(a.h1==b.h1)
	{
		if(a.h2==b.h2)return a.y<b.y;
		return a.h2<b.h2;
	}
	return a.h1<b.h1;
}
int head[1100000],p[1100000],next[1100000];int tot=0;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		data[i].h1=0;
		data[i].h2=1;
		data[i].y=1;
	}
	while(m--)
	{
		int a,b;scanf("%d%d",&a,&b);
		data[a].h1^=b;
		data[a].h2=data[a].h2*1ll*b%mod2;
		data[a].y*=(ull)b;
		tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;
		data[b].h1^=a;
		data[b].h2=data[b].h2*1ll*a%mod2;
		data[b].y*=(ull)a;
	}
	//for(int i=1;i<=n;i++)printf("%d %d %I64u\n",data[i].h1,data[i].h2,data[i].y);
	ull ans=0;
	for(int i=1;i<=n;i++)
	for(int u=head[i];u;u=next[u])
	{
		int j=p[u];
		if(((data[j].h1^j)==(data[i].h1^i))&&((data[j].h2*1ll*j%mod2)==(data[i].h2*1ll*i%mod2))&&((data[j].y*j)==(data[i].y*i)))ans=ans+(ull)1;
	}
	sort(data+1,data+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(j<n&&data[j+1].h1==data[i].h1&&data[j+1].h2==data[i].h2&&data[j+1].y==data[i].y)j++;
		ans+=((ull)(j-i+1))*(j-i)/2;
		i=j;
		}
	printf("%I64u\n",ans);
	return 0;
}