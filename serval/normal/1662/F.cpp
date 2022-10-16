#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pa pair<int,int>
const int N=200010;
LL read()
{
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10ll+ch-'0',ch=getchar();
	return x*f;
}
int n,a,b,p[N];
int mn[N<<2],pmn[N<<2],mx[N<<2],pmx[N<<2],f[N];
void up(int x)
{
	int lc=(x<<1),rc=(x<<1|1);
	
	if(mn[lc]<=mn[rc])pmn[x]=pmn[lc],mn[x]=mn[lc];
	else pmn[x]=pmn[rc],mn[x]=mn[rc];
	
	if(mx[lc]>=mx[rc])pmx[x]=pmx[lc],mx[x]=mx[lc];
	else pmx[x]=pmx[rc],mx[x]=mx[rc];
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		mx[x]=l+p[l];pmx[x]=l;
		mn[x]=l-p[l];pmn[x]=l;
		return;
	}
	int mid=l+r>>1;
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	up(x);
}
void del(int x,int l,int r,int p)
{
	if(l==r)
	{
		mx[x]=INT_MIN;
		mn[x]=INT_MAX;
		return;
	}
	int mid=l+r>>1;
	if(p<=mid)del(x<<1,l,mid,p);
	else del(x<<1|1,mid+1,r,p);
	up(x);
}
pa gmx(int x,int l,int r,int ql,int qr)
{
//	printf("%d %d %d %d\n",l,r,ql,qr);
	if(l==ql&&r==qr)return make_pair(mx[x],pmx[x]);
	int mid=l+r>>1;
	if(qr<=mid)return gmx(x<<1,l,mid,ql,qr);
	if(ql>mid)return gmx(x<<1|1,mid+1,r,ql,qr);
	pa L=gmx(x<<1,l,mid,ql,mid);
	pa R=gmx(x<<1|1,mid+1,r,mid+1,qr);
	if(L.first>=R.first)return L;
	return R;
}
pa gmn(int x,int l,int r,int ql,int qr)
{
//	printf("%d %d %d %d\n",l,r,ql,qr);
	if(l==ql&&r==qr)return make_pair(mn[x],pmn[x]);
	int mid=l+r>>1;
	if(qr<=mid)return gmn(x<<1,l,mid,ql,qr);
	if(ql>mid)return gmn(x<<1|1,mid+1,r,ql,qr);
	pa L=gmn(x<<1,l,mid,ql,mid);
	pa R=gmn(x<<1|1,mid+1,r,mid+1,qr);
	if(L.first<=R.first)return L;
	return R;
}
void solve()
{
	n=read(),a=read(),b=read();
	for(int i=1;i<=n;i++)p[i]=read();
	for(int i=0;i<=n;i++)f[i]=INT_MAX;
	build(1,1,n);
	f[a]=0;
	del(1,1,n,a);
	queue<int>q;
	q.push(a);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		pa t;
		t=gmn(1,1,n,x,min(n,x+p[x]));
		while(t.first<=x)
		{
			int y=t.second;
//			printf("%d y1 = %d\n",t.first,y);
			f[y]=f[x]+1;
			q.push(y);
			del(1,1,n,y);
			t=gmn(1,1,n,x,min(n,x+p[x]));
		}
		t=gmx(1,1,n,max(1,x-p[x]),x);
		while(t.first>=x)
		{
			int y=t.second;
//			printf("%d y2 = %d\n",t.first,y);
			f[y]=f[x]+1;
			q.push(y);
			del(1,1,n,y);
			t=gmx(1,1,n,max(1,x-p[x]),x);
		}
	}
	printf("%d\n",f[b]);
}
int main()
{
	int T=read();
	while(T--)solve();
 	return 0;
}