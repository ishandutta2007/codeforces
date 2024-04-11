#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 410000
#define MAXM 410000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n;
int tx,ty;
string s[MAXN];
int x[MAXN],y[MAXN];
int xmax,xmin,ymax,ymin,dmax,dmin;

void updmax(int &x,int y)
{
	x=max(x,y);
}

void updmin(int &x,int y)
{
	x=min(x,y);
}


bool inhexagon(int x,int y,int r)
{
	return x>=tx && y>=ty && x<=tx+2*r && y<=ty+2*r && y-x>=ty-tx-r && y-x<=ty-tx+r;
}

bool check(int r)
{
	xmax=ymax=dmax=INF;
	xmin=ymin=dmin=-INF;
	for (int i=0;i<n;i++)
	{
		updmax(xmin,x[i]-r);
		updmin(xmax,x[i]+r);
		updmax(ymin,y[i]-r);
		updmin(ymax,y[i]+r);
		updmax(dmin,y[i]-x[i]-r);
		updmin(dmax,y[i]-x[i]+r);
	}
	//cout<<r<<' '<<xmin<<' '<<xmax<<' '<<ymin<<' '<<ymax<<' '<<dmin<<' '<<dmax<<endl;
	 
	return !(xmax<xmin || ymax<ymin || dmax<dmin || ymax-xmin<dmin || ymin-xmax>dmax);
} 

void cnt(int i)
{
	for (auto p:s[i])
		if (p=='N')
			x[i]++;
		else
			y[i]++; 
}

int main()
{
	cin>>n;
	tx=INF;
	ty=INF;
	for (int i=0;i<n;i++)
	{
		cin>>s[i];
		cnt(i);
	}
	//cout<<tx<<' '<<ty<<endl;
	int l=0,r=500000;
	while (l<r)
	{
		int mid=(l+r)/2;
		if (check(mid))
			r=mid;
		else
			l=mid+1;
	}
	check(r);
	int d=min(dmax,ymax-xmin);
	//WRT(d);
	if (xmax+d>=ymin && xmax+d<=ymax)
	{
		tx=xmax;
		ty=xmax+d;
	}
	else
	{
		tx=ymax-d;
		ty=ymax;
	}
	cout<<r<<endl;
	for (int i=0;i<tx;i++)
		putchar('N');
	for (int i=0;i<ty;i++)
		putchar('B');
	return ~~(0^_^0);
}