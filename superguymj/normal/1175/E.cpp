#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)
#define pb push_back

using namespace std;
const int N=200005;
int n,m,tot,fa[30][N];
struct data{int l,r;} dat[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

bool cmp(data a,data b)
{
	return a.l==b.l?a.r>b.r:a.l<b.l;
}

int main()
{	
	n=getint(),m=getint();
	rep(i,1,n) dat[i].l=getint(),dat[i].r=getint();
	sort(dat+1,dat+1+n,cmp);
	int mx=0;
	rep(i,1,n)
		if(dat[i].r>mx)
			mx=dat[i].r,dat[++tot]=dat[i];
	int p=0;
	n=tot;
	rep(i,1,n)
	{
		while(p+1<=n && dat[p+1].l<=dat[i].r) ++p;
		fa[0][i]=p;
	}
	rep(i,1,20) rep(j,1,n) fa[i][j]=fa[i-1][fa[i-1][j]];
	rep(i,1,m)
	{
		int ql=getint(),qr=getint();
		int l=1,r=n;
		while(l<=r) dat[mid].l<=ql?l=mid+1:r=mid-1;
		int x=l-1,ans=1;
		if(dat[x].r>=qr) {puts("1"); continue;}
		repd(j,20,0) if(dat[fa[j][x]].r<qr) x=fa[j][x],ans+=(1<<j);
		++ans;
		if(ans>n) puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}