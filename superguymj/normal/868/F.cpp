#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)

using namespace std;
const int N=100005,K=22;
int n,k,a[N],L,R;
typedef long long LL;
LL f[K][N],c[N],tot;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void solve(int x,int l,int r,int ansl,int ansr)
{
	if(l>r) return;	
	int Mid=min(ansr,mid-1)+1;
	while(R<mid) ++R,tot+=c[a[R]],++c[a[R]];
	while(R>mid) --c[a[R]],tot-=c[a[R]],--R;
	while(L>Mid) --L,tot+=c[a[L]],++c[a[L]];
	while(L<Mid) --c[a[L]],tot-=c[a[L]],++L;
	repd(i,Mid-1,ansl)
	{
		if(f[x-1][i]+tot<f[x][mid]) f[x][mid]=f[x-1][i]+tot,Mid=i;
		--L,tot+=c[a[L]],++c[a[L]];
	}
	solve(x,l,mid-1,ansl,Mid);
	solve(x,mid+1,r,Mid,ansr);
}

int main()
{
	n=getint(),k=getint();
	rep(i,1,n) a[i]=getint();
	rep(i,1,n) f[1][i]=f[1][i-1]+c[a[i]],++c[a[i]];
	memset(c,0,sizeof(c));
	rep(i,2,k)
	{
		L=1,R=tot=0,memset(c,0,sizeof(c));
		rep(j,1,n) f[i][j]=1e18;
		solve(i,i,n,i-1,n-1);
	}
	printf("%I64d\n",f[k][n]);
	return 0;
}