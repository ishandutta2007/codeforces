#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
const int N=400005;
int n,pool[N],t[N<<2],a[N],b[N],x;
long long ans;
vector <int> bin[N];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

int find(int x)
{
	int l=1,r=n+n;
	while(l<=r)
		pool[mid]<=x?l=mid+1:r=mid-1;
	return l-1;
}

void ins(int l,int r,int rt,int x,int y)
{
	if(l==r)
	{
		t[rt]+=y;
		return;
	}
	if(x<=mid) ins(l,mid,lch,x,y);
	else ins(mid+1,r,rch,x,y);
	t[rt]=t[lch]+t[rch];
}

int query(int l,int r,int rt,int ql,int qr)
{
	if(ql<=l && r<=qr) return t[rt];
	if(qr<=mid) return query(l,mid,lch,ql,qr);
	if(mid<ql) return query(mid+1,r,rch,ql,qr);
	return query(l,mid,lch,ql,qr)+query(mid+1,r,rch,ql,qr);
}

int main()
{
	n=getint();
	rep(i,1,n) pool[i]=i;
	rep(i,1,n) a[i]=getint(),pool[i+n]=a[i];
	sort(pool+1,pool+1+n+n);
	rep(i,1,n) b[i]=find(a[i]);
	rep(i,1,n)
	{
		int siz=bin[i].size();
		rep(j,0,siz-1) ins(1,2*n,1,bin[i][j],-1);
		ans+=query(1,2*n,1,1,b[i]);
		if(i<=a[i]) ins(1,2*n,1,x=find(i),1);
		if(i<=a[i] && a[i]<=n) bin[a[i]+1].push_back(x);
	}
	printf("%I64d\n",ans);
	return 0;
}