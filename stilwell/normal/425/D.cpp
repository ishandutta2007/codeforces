#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int x[100005],y[100005],r[100005],d[100005],rsum[100005],dsum[100005];
int n,i,j,k,ans;
int son[1000005],next[100005];
long long val[100005];

struct node
{
	int x,y,id;
}t[100005];

inline bool cmpx(const node &a,const node &b){if(a.x!=b.x)return a.x<b.x;return a.y<b.y;}
inline bool cmpy(const node &a,const node &b){if(a.y!=b.y)return a.y<b.y;return a.x<b.x;}

long long get_val(int x,int y)
{
	x+=1000000;y+=1000000;
	return (long long)x*10000000+y;
}
int h;
long long tmp;
bool find(int x,int y)
{
	tmp=get_val(x,y);
	for(h=son[tmp%999997];h;h=next[h])
	if(val[h]==tmp)return true;
	return false;
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&x[i],&y[i]);
		t[i].x=x[i];
		t[i].y=y[i];
		t[i].id=i;
		val[i]=get_val(x[i],y[i]);
		next[i]=son[val[i]%999997];
		son[val[i]%999997]=i;
	}
	sort(t+1,t+n+1,cmpx);
	for(i=n;i>=1;--i)
	if(i==n||t[i].x!=t[i+1].x)rsum[t[i].id]=1;
	else r[t[i].id]=t[i+1].id,rsum[t[i].id]=rsum[t[i+1].id]+1;
	sort(t+1,t+n+1,cmpy);
	for(i=n;i>=1;--i)
	if(i==n||t[i].y!=t[i+1].y)dsum[t[i].id]=1;
	else d[t[i].id]=t[i+1].id,dsum[t[i].id]=dsum[t[i+1].id]+1;
	for(i=1;i<=n;++i)
	if(rsum[i]<dsum[i])
	{
		for(j=r[i];j;j=r[j])
		{
			k=y[j]-y[i];
			if(find(x[i]+k,y[i])&&find(x[i]+k,y[i]+k))
			++ans;
		}
	}
	else
	{
		for(j=d[i];j;j=d[j])
		{
			k=x[j]-x[i];
			if(find(x[i],y[i]+k)&&find(x[i]+k,y[i]+k))
			++ans;
		}
	}
	printf("%d\n",ans);
}