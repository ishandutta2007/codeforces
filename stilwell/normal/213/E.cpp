#include <stdio.h>
#include <stdlib.h>
#define h 233333
using namespace std;

int n,m,i,j,k,l,ans,aim,tmp,tmp2;
int a[200005],b[200005],c[200005];
int size[800005];
unsigned long long power[800005],H[800005],A;
bool t[800005];

void C(int x)
{
	int i=l+x-1;
	t[i]^=1;
	for(i>>=1;i;i>>=1)t[i]=t[i<<1]|t[i<<1|1];
}

void Pre(int x,int l,int r)
{
	if(l>=aim||!t[x])return;
	if(l==r)
	{
		tmp=l;
		return;
	}
	int mid=l+r>>1;
	Pre(x<<1|1,mid+1,r);
	if(tmp)return;
	Pre(x<<1,l,mid);
}

void Suc(int x,int l,int r)
{
	if(r<=aim||!t[x])return;
	if(l==r)
	{
		tmp=l;
		return;
	}
	int mid=l+r>>1;
	Suc(x<<1,l,mid);
	if(tmp)return;
	Suc(x<<1|1,mid+1,r);
}

int left(int x)
{
	tmp=0;aim=x;
	Pre(1,1,l);
	return tmp;
}

int right(int x)
{
	tmp=0;aim=x;
	Suc(1,1,l);
	return tmp;
}

void M(int x,int l,int r)
{
	if(l==r)
	{
		H[x]=tmp;
		size[x]=tmp2;
		return;
	}
	int mid=l+r>>1;
	if(aim<=mid)M(x<<1,l,mid);
	else M(x<<1|1,mid+1,r);
	H[x]=H[x<<1]*power[size[x<<1|1]]+H[x<<1|1];
	size[x]=size[x<<1]+size[x<<1|1];
}

void ins(int x)
{
	x=c[x];
	int L,R;
	C(x);
	L=left(x);
	R=right(x);
	if(L)tmp=b[x]-b[L];
	else tmp=0;
	tmp2=1;aim=x;
	M(1,1,m);
	if(R)
	{
		tmp=b[R]-b[x];
		tmp2=1;aim=R;
		M(1,1,m);
	}
}

void del(int x)
{
	x=c[x];
	int L,R;
	C(x);
	L=left(x);
	R=right(x);
	tmp=tmp2=0;aim=x;
	M(1,1,m);
	if(R)
	{
		if(L)tmp=b[R]-b[L];
		else tmp=0;
		tmp2=1;aim=R;
		M(1,1,m);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(l=1;l<m;l*=2);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=m;++i)scanf("%d",&b[i]),c[b[i]]=i;
	for(i=2;i<=n;++i)A=A*h+a[i]-a[i-1];
	power[0]=1;
	for(i=1;i<=n;++i)power[i]=power[i-1]*h;
	for(i=1;i<=n;++i)ins(i);
	if(H[1]==A)++ans;
	for(i=n+1;i<=m;++i)
	{
		ins(i);del(i-n);
		if(H[1]==A)++ans;
	}
	printf("%d\n",ans);
}