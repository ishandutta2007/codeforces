#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)

using namespace std;
const int N=105;
bool ans[N][N];
int n,p[N];

bool q1(int x,int y)
{
	int ret;
	printf("1 %d %d\n",x-1,y-1);
	fflush(stdout);
	scanf("%d",&ret);
	return ret;
}

bool q2(int x,int y)
{
	int ret;
	printf("2 %d %d",p[x]-1,y);
	rep(i,1,y) printf(" %d",p[i]-1);
	puts(""),fflush(stdout);
	scanf("%d",&ret);
	return ret;
}

void init(int l,int r)
{
	rep(i,l,r) rep(j,l,r) ans[p[i]][p[j]]=1;
	rep(i,l,r) rep(j,r+1,n) ans[p[i]][p[j]]=1;
}

void solve()
{
	scanf("%d",&n);
	p[1]=1;
	rep(i,2,n)
	{
		if(q1(p[i-1],i)) p[i]=i;
		else if(q1(i,p[1]))
		{
			repd(j,i-1,1) p[j+1]=p[j];
			p[1]=i;
		}
		else
		{
			int l=1,r=i-1;
			while(l+1<r)
				q1(p[mid],i)?l=mid:r=mid;
			repd(j,i-1,r) p[j+1]=p[j];
			p[r]=i;
		}
	}
	rep(i,1,n) rep(j,1,n) ans[i][j]=0;
	int x=n+1,lst=n;
	repd(i,n,1)
	{
		if(i<x)
			init(x,lst),lst=x=i;
		while(x>1 && q2(i,x-1)) --x;
	}
	init(x,lst),puts("3");
	rep(i,1,n)
	{
		rep(j,1,n) putchar('0'+ans[i][j]);
		puts("");
	}
	fflush(stdout),scanf("%d",&x);
}
			

int main()
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}