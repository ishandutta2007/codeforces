#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)

using namespace std;
typedef long long LL;
const int N=204;
const LL INF=1000000000000000000;
int n,k;
struct data
{
	int ans;
	LL S;

	void chkmax(data x)
	{
		if(x.ans>ans || (x.ans==ans && x.S>S))
			ans=x.ans,S=x.S;
	}
} f[N][N];

struct point
{
	LL x,y;
} p[N];

point operator - (point a,point b)
{
	return (point){a.x-b.x,a.y-b.y};
}

LL operator * (point a,point b)
{
	return a.x*b.y-a.y*b.x;
}

data operator + (data x,data y)
{
	return (data){x.ans+y.ans,x.S+y.S};
}

bool check(LL S)
{
	rep(j,3,n) repd(i,j-2,1)
	{
		f[i][j]=(data){0,0};
		rep(k,i,j)
		{
			data tmp=f[i][k]+f[k][j];
			tmp.S+=abs((p[i]-p[k])*(p[j]-p[k]));
			if(tmp.S>=S) tmp.S=0,++tmp.ans;
			f[i][j].chkmax(tmp);
		}
	}
	return f[1][n].ans>k;
}

int main()
{
	scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%lld%lld",&p[i].x,&p[i].y);
	LL l=1,r=INF;
	while(l<=r) check(mid)?l=mid+1:r=mid-1;
	printf("%lld\n",l-1);
	return 0;
}