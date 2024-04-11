#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,x,y,ans;
int Max[100005],f[100005];
long long a,b,c,d,now;

struct node
{
	long long x,y;
}t[100005];
inline bool cmpx(const node &a,const node &b)
{
	if(a.x!=b.x)return a.x<b.x;
	return a.y>b.y;
}
inline bool cmpy(const node &a,const node &b)
{
	if(a.y!=b.y)return a.y<b.y;
	return a.x<b.x;
}

char ch;
void read(long long &x)
{
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
	for(x=0;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
}

int main()
{
	scanf("%d",&m);
	read(a);read(b);read(c);read(d);
	for(;m;--m)
	{
		scanf("%d%d",&x,&y);
		++n;
		t[n].x=b*y-a*x;
		t[n].y=c*x-d*y;
		if(t[n].x<=0)--n;
		else if(t[n].y<=0)--n;
	}
	sort(t+1,t+n+1,cmpy);
	for(i=1;i<=n;++i)
	{
		if(t[i].y!=now||i==1)++m,now=t[i].y;
		t[i].y=m;
	}
	sort(t+1,t+n+1,cmpx);
	for(i=1;i<=n;++i)
	{
		k=0;
		for(j=t[i].y-1;j;j-=j&-j)if(f[j]>k)k=f[j];
		++k;
		if(k>ans)ans=k;
		for(j=t[i].y;j<=n;j+=j&-j)if(k>f[j])f[j]=k;
	}
	printf("%d\n",ans);
}