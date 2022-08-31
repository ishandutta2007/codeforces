#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
#define jsb 1000000007
using namespace std;
#define MAXN 110000
int q[MAXN];int n;
int b[MAXN];
int fac[MAXN];int nw[MAXN];
int Pow(int a,int b)
{
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%jsb)
	if(b&1)c=c*1ll*a%jsb;
	return c;
}
int check(int a,int b)
{
	return (fac[a+b]*1ll*nw[a]%jsb)*1ll*nw[b]%jsb;
}
struct jdb
{
	int x,y;
}data[MAXN];int tot=0;
bool cmp(jdb a,jdb b){return a.y<b.y;}
int calc(int x)
{
	if(x==0)return 1;
	return Pow(2,x-1);
}
int main()
{
	scanf("%d",&n);fac[0]=nw[0]=1;
	rep(i,1,n){fac[i]=fac[i-1]*1ll*i%jsb;nw[i]=Pow(fac[i],jsb-2);}
	rep(i,1,n)
	{
		int v;scanf("%d",&v);
		if(v)
		{
			++tot;
			data[tot].x=i;
			data[tot].y=v;
		}
	}
	sort(data+1,data+1+tot,cmp);
	rep(i,1,tot){q[++q[0]]=data[i].y;b[q[0]]=data[i].x;}
	//rep(i,1,q[0])printf("__%d %d\n",q[i],b[i]);
	if(q[0]==0){printf("%d\n",Pow(2,n-1));return 0;}
	int cl,cr;cl=0;cr=0;
	if(b[1]>=q[1])cr=calc(q[1]-1);
	if(q[1]-1+b[1]<=n)cl=calc(q[1]-1);
	rep(i,2,q[0])
	{
		int l,r;
		int nl,nr;nl=nr=0;
		l=b[i-1];r=b[i-1]+q[i-1]-1;
		if(r<=n&&l<=r)
		{
			if(b[i]<l)
			{
				if(b[i]+q[i]-1<=n&&b[i]+q[i]-1>=r)
				{
					nl=(nl+cl*1ll*check(l-b[i]-1,b[i]+q[i]-1-r))%jsb;
				}
			}
			if(b[i]>r)
			{
				if(b[i]>=q[i]&&b[i]-q[i]+1<=l)
				{
					nr=(nr+cl*1ll*check(l-(b[i]-q[i]+1),b[i]-r-1))%jsb;
				}
			}
		}
		r=b[i-1];l=b[i-1]-q[i-1]+1;
		//printf("__%d %d\n",nl,nr);
		if(l>0&&l<r)
		{
			if(b[i]<l)
			{
				if(b[i]+q[i]-1<=n&&b[i]+q[i]-1>=r)
				{
					nl=(nl+cr*1ll*check(l-b[i]-1,b[i]+q[i]-1-r))%jsb;
				}
			}
			
			if(b[i]>r)
			{
				if(b[i]>=q[i]&&b[i]-q[i]+1<=l)
				{
					nr=(nr+cr*1ll*check(l-(b[i]-q[i]+1),b[i]-r-1))%jsb;
				}
			}
		}
		cl=nl;cr=nr;
	}
	int res=0;
	int l,r;
	l=b[q[0]];r=b[q[0]]+q[q[0]]-1;if(r<=n&&l<=r)res=(res+cl*1ll*check(l-1,n-r))%jsb;
	r=b[q[0]];l=b[q[0]]-q[q[0]]+1;if(l>0&&l<r)res=(res+cr*1ll*check(l-1,n-r))%jsb;
	printf("%d\n",res);
	return 0;
}