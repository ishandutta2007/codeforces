#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)

using namespace std;
const int N=100005;
int n,a[10],pool[N],ql,qr,x,tot,root[N];
struct data{int x,y;} dat[N];
struct seg{int l,r,s;} t[N*20];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

bool cmp(data a,data b)
{
	return a.x<b.x;
}

int find(int x)
{
	int l=1,r=n;
	while(l<=r)
		pool[mid]<=x?l=mid+1:r=mid-1;
	return l-1;
}

void build(int l,int r,int rt)
{
	if(l==r) return;
	build(l,mid,t[rt].l=++tot);
	build(mid+1,r,t[rt].r=++tot);
}

void insert(int l,int r,int lst,int rt)
{
	if(l==r)
	{
		t[rt].s=t[lst].s+1;
		return;
	}
	if(x<=mid) insert(l,mid,t[lst].l,t[rt].l=++tot),t[rt].r=t[lst].r;
	else insert(mid+1,r,t[lst].r,t[rt].r=++tot),t[rt].l=t[lst].l;
	t[rt].s=t[t[rt].l].s+t[t[rt].r].s;
}

int query(int l,int r,int lst,int rt)
{
	if(ql<=l && r<=qr) return t[rt].s-t[lst].s;
	if(qr<=mid) return query(l,mid,t[lst].l,t[rt].l);
	if(ql>mid) return query(mid+1,r,t[lst].r,t[rt].r);
	return query(l,mid,t[lst].l,t[rt].l)+query(mid+1,r,t[lst].r,t[rt].r);
}

int main()
{
	n=getint();
	rep(i,1,n) dat[i].x=getint(),dat[i].y=getint(),pool[i]=dat[i].y;
	sort(pool+1,pool+1+n),sort(dat+1,dat+1+n,cmp);
	rep(i,1,n) dat[i].y=find(dat[i].y);
	build(1,n,root[0]=tot=1);
	rep(i,1,n) x=dat[i].y,insert(1,n,root[i-1],root[i]=++tot);
	rep(i,1,9) a[i]=getint();
	sort(a+1,a+10);
	do
	{
		int p=a[1]+a[2]+a[3];
		if(dat[p].x==dat[p+1].x) continue;
		p+=a[4]+a[5]+a[6];
		if(dat[p].x==dat[p+1].x) continue;
		p=a[1]+a[4]+a[7];
		if(pool[p]==pool[p+1]) continue;
		p+=a[2]+a[5]+a[8];
		if(pool[p]==pool[p+1]) continue;
		
		int p1=a[1]+a[4]+a[7],p2=a[2]+a[5]+a[8],p3=a[1]+a[2]+a[3],p4=a[4]+a[5]+a[6];
		if(ql=1,qr=p1,a[1]!=query(1,n,root[0],root[p3]) || a[4]!=query(1,n,root[p3],root[p3+p4])) continue;
		if(ql=p1+1,qr=p1+p2,a[2]!=query(1,n,root[0],root[p3]) || a[5]!=query(1,n,root[p3],root[p3+p4])) continue;
	
		printf("%.10lf %.10lf\n",dat[a[1]+a[2]+a[3]].x+0.5,dat[a[1]+a[2]+a[3]+a[4]+a[5]+a[6]].x+0.5);
		printf("%.10lf %.10lf\n",pool[a[1]+a[4]+a[7]]+0.5,pool[a[1]+a[4]+a[7]+a[2]+a[5]+a[8]]+0.5);
		return 0;

	}while(next_permutation(a+1,a+10));
	puts("-1");
	return 0;
}