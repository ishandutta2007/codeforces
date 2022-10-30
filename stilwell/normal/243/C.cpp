#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,tot;
bool f[5001][5001],v[5001][5001];
int lx[5000],ly[5000],cntx,cnty,nx,ny;
int qx[6000001],qy[6000001],t1,t2;
int x,y;
char ch;
long long ans;

struct node
{
	int x[2],y[2];
}l[1001];

struct dis
{
	int val,id,id2;
}t[3000];

inline bool cmp(const dis &a,const dis &b)
{
	if(a.val!=b.val)return a.val<b.val;
	if(a.id!=b.id)return a.id<b.id;
	return a.id2<b.id2;
}

void inq(int x,int y)
{
	if(x<1||y<1||x>cntx||y>cnty)return;
	if(v[x][y])return;
	if(f[x][y])return;
	v[x][y]=true;
	++t2;
	qx[t2]=x;
	qy[t2]=y;
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		ch=getchar();
		while(ch!='U'&&ch!='D'&&ch!='L'&&ch!='R')ch=getchar();
		scanf("%d",&k);
		if(ch=='U')l[i].x[0]=x,l[i].y[0]=y,x+=k,l[i].x[1]=x,l[i].y[1]=y;
		if(ch=='D')l[i].x[0]=x,l[i].y[0]=y,x-=k,l[i].x[1]=x,l[i].y[1]=y;
		if(ch=='L')l[i].x[0]=x,l[i].y[0]=y,y-=k,l[i].x[1]=x,l[i].y[1]=y;
		if(ch=='R')l[i].x[0]=x,l[i].y[0]=y,y+=k,l[i].x[1]=x,l[i].y[1]=y;
		if(l[i].x[0]>l[i].x[1])swap(l[i].x[0],l[i].x[1]);
		if(l[i].y[0]>l[i].y[1])swap(l[i].y[0],l[i].y[1]);
	}
	
	tot=0;
	for(i=1;i<=n;++i)
	{
		++tot;t[tot].val=l[i].x[0];t[tot].id=i;t[tot].id2=0;
		++tot;t[tot].val=l[i].x[1];t[tot].id=i;t[tot].id2=1;
	}
	sort(t+1,t+tot+1,cmp);
	t[0].val=t[1].val-1;
	for(i=1;i<=tot;++i)
	{
		if(t[i].val!=t[i-1].val)
		{
			if(t[i].val!=t[i-1].val+1)
			lx[++cntx]=t[i].val-t[i-1].val-1;
			lx[++cntx]=1;
		}
		l[t[i].id].x[t[i].id2]=cntx;
	}
	
	tot=0;
	for(i=1;i<=n;++i)
	{
		++tot;t[tot].val=l[i].y[0];t[tot].id=i;t[tot].id2=0;
		++tot;t[tot].val=l[i].y[1];t[tot].id=i;t[tot].id2=1;
	}
	sort(t+1,t+tot+1,cmp);
	t[0].val=t[1].val-1;
	for(i=1;i<=tot;++i)
	{
		if(t[i].val!=t[i-1].val)
		{
			if(t[i].val!=t[i-1].val+1)
			ly[++cnty]=t[i].val-t[i-1].val-1;
			ly[++cnty]=1;
		}
		l[t[i].id].y[t[i].id2]=cnty;
	}
	for(i=1;i<=n;++i)
	for(j=l[i].x[0];j<=l[i].x[1];++j)
	for(k=l[i].y[0];k<=l[i].y[1];++k)
	f[j][k]=true;
	for(i=1;i<=cntx;++i)
	for(j=1;j<=cnty;++j)
	if((i==1||i==cntx)||(j==1||j==cnty))
	if(!v[i][j])
	if(!f[i][j])
	{
		t1=0;t2=1;
		qx[1]=i;
		qy[1]=j;
		v[i][j]=true;
		while(t1<t2)
		{
			++t1;
			nx=qx[t1];ny=qy[t1];
			inq(nx-1,ny);
			inq(nx+1,ny);
			inq(nx,ny-1);
			inq(nx,ny+1);
		}
	}
	for(i=1;i<=cntx;++i)
	for(j=1;j<=cnty;++j)
	if(!v[i][j])ans+=(long long)lx[i]*ly[j];
	printf("%I64d\n",ans);
}