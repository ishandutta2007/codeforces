#include<bits/stdc++.h>
using namespace std;
#define MN 200000
#define K 31
#define L (k<<1)
#define R (k<<1|1)
long long a[MN+5],s[MN+5];
struct node{long long mx[K],mk;int id[K];}t[524288];
inline void up(int k)
{
	int i,a=0,b=0;
	for(i=0;i<K;++i)
		if(t[L].mx[a]>t[R].mx[b])
			t[k].mx[i]=t[L].mx[a],t[k].id[i]=t[L].id[a++];
		else
			t[k].mx[i]=t[R].mx[b],t[k].id[i]=t[R].id[b++];
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		t[k].mx[0]=s[l];
		t[k].id[0]=l;
		for(int i=1;i<K;++i)t[k].mx[i]=-1e18;
		return;
	}
	int mid=l+r>>1;
	build(L,l,mid);build(R,mid+1,r);up(k);
}
void add(int k,long long x)
{
	for(int i=0;i<K;++i)t[k].mx[i]+=x;
	t[k].mk+=x;
}
inline void down(int k){if(t[k].mx)add(L,t[k].mk),add(R,t[k].mk),t[k].mk=0;}
void add(int k,int l,int r,int ql,int qr,int x)
{
	if(l==ql&&r==qr){add(k,x);return;}
	int mid=l+r>>1;down(k);
	if(qr<=mid)add(L,l,mid,ql,qr,x);
	else if(ql>mid)add(R,mid+1,r,ql,qr,x);
	else add(L,l,mid,ql,mid,x),add(R,mid+1,r,mid+1,qr,x);
	up(k);
}
int main()
{
	int n,q,i,x,y;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	for(i=n;i;--i)s[i]=a[i]-s[i-1];
	build(1,1,n);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		add(1,1,n,x,x,y-a[x]);
		if(x<n)add(1,1,n,x+1,n,a[x]-y);
		a[x]=y;
		for(i=0;i<K;++i)if(t[1].mx[i]==0)break;
		printf("%d\n",i<K?t[1].id[i]:-1);
	}
}