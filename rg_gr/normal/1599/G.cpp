#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int inf=1e18;
const double eps=1e-12;
const int M=2e5+10;
int n,s;
double sum[M];
pair<int,int>d[M];

double dis(pair<int,int>d1,pair<int,int>d2)
{
	double p=(d1.x-d2.x)*(d1.x-d2.x)+(d1.y-d2.y)*(d1.y-d2.y);
	return sqrt(p);
}

void SWAP(int x,int y)
{
	swap(d[x],d[y]);
	if (x==s)s=y;
	else if (y==s)s=x;
}

pair<double,double>get(pair<int,int>a,pair<int,int>b)
{
	int dx=a.x-b.x,dy=a.y-b.y;
	if (dx==0)return mp(inf,0.0);
	else return mp(dy*1.0/dx,a.y-dy*1.0/dx*a.x);
}

bool check(int a,int b,int c)//a,b,c /tuu 
{
	pair<double,double>x1=get(d[a],d[b]),x2=get(d[b],d[c]);
	return fabs(x1.x-x2.x)<=eps&&fabs(x1.y-x2.y)<=eps;
}

signed main()
{
//	freopen("qwq.txt","r",stdin);
//	freopen("1.out","w",stdout);
	n=read(),s=read();
	for (int i=1;i<=n;i++)
		d[i].x=read(),d[i].y=read();
	if (n>3)
	{
		if (check(1,2,4))SWAP(3,4);
		else if (check(1,3,4))SWAP(2,4);
		else if (check(2,3,4))SWAP(1,4);
		for (int i=4;i<=n;i++)
			if (!check(1,2,i))SWAP(i,n);
	}
	if (s==n)
	{
//		assert(0);
		sort(d+1,d+n);double ans=inf;
		for (int i=2;i<n;i++)
			sum[i]=sum[i-1]+dis(d[i],d[i-1]);
		for (int i=1;i<n;i++)
			ans=min(ans,sum[n-1]+min(sum[i],sum[n-1]-sum[i])+dis(d[n],d[i]));
		printf("%.6lf",ans);
		return 0;
	}
	pair<int,int>x=d[s];
	sort(d+1,d+n);
	for (int i=1;i<n;i++)
	{
		if (x==d[i])s=i;
		if (i!=1)
			sum[i]=sum[i-1]+dis(d[i],d[i-1]);
	}
	//1 ~ n-1  n  s  
	pair<double,double>X=get(d[1],d[2]);
	double k=X.x<=eps?inf:-1.0/X.x;
	double ans=min(sum[n-1]-sum[s]+dis(d[n],d[n-1])+(s==1?0:min(dis(d[n],d[s-1]),dis(d[n],d[1]))+sum[s-1]),
	sum[s]+dis(d[1],d[n])+(s==n-1?0:(min(dis(d[n],d[s+1]),dis(d[n],d[n-1]))+sum[n-1]-sum[s+1])));
//	cout<<ans<<endl;
	for (int i=1;i<s;i++)
		ans=min(ans,sum[s]-sum[i]+sum[n-1]+dis(d[n-1],d[n])+(i==1?0:min(dis(d[1],d[n]),dis(d[i-1],d[n])))+sum[i-1]);
	for (int i=s+1;i<n;i++)
		ans=min(ans,sum[i]*2-sum[s]+dis(d[1],d[n])+(i==n-1?0:min(dis(d[n],d[i+1]),dis(d[n],d[n-1]))+sum[n-1]-sum[i+1]));
	double b=d[n].y-k*d[n].x;
	double dx=(b-X.y)*1.0/(X.x-k),dy=k*dx+b;
	double val=inf;
	for (int i=1;i<n-1;i++)
		val=min(val,dis(d[i],d[n])+dis(d[i+1],d[n])-dis(d[i],d[i+1]));
	ans=min(ans,val+sum[n-1]+min(sum[s],sum[n-1]-sum[s]));
	printf("%.6lf",ans);
	return 0;
}