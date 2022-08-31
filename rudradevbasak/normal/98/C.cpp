//Data Structure includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>


//Other Includes
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

#define FOR(i,a,b)					for(int i=a;i<b;i++)
#define REP(i,n)					FOR(i,0,n)
#define pb						 	push_back
#define mp						 	make_pair
#define s(n)						scanf("%d",&n)
#define sl(n) 						scanf("%lld",&n)
#define sf(n) 						scanf("%lf",&n)
#define ss(n) 						scanf("%s",n)
#define fill(a,v) 					memset(a, v, sizeof a)
#define sz							size()
#define INF							(int)1e9
#define EPS							1e-9
#define bitcount					__builtin_popcount
#define all(x)						x.begin(), x.end()
#define gcd							__gcd
#define maX(a,b)					(a>b?a:b)
#define miN(a,b)					(a<b?a:b)

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef long long LL;
typedef pair<int, int > PII;

/*Main code begins now */
int testnum;
double a,b,l;


void preprocess()
{

}

double value(double x)
{
	double y,z,det;
	y = sqrt(l*l - x*x);
	x = 1/x;
	y = 1/y;
	det = sqrt(x*x + y*y);
	det = (a*x + b*y- 1)/det;
	return det;
}

void solve()
{
	double lo = 0;
	double hi = l;
	double x,y,vx,vy;
	for(int i=0;i<1000;i++)
	{
		x = (lo+lo+hi)/3;
		y = (lo+hi+hi)/3;
		vx = value(x);
		vy = value(y);
		if(vx<vy)
			hi = y;
		else
			lo = x;
	}
	
	vx = value(lo);
	//printf("%lf %lf %lf %lf\n",a,b,lo,vx);
	//if(vx>l) vx=l;
	//if(l<=a && l<=b) vx=max(vx,l);
	if(l<=a) vx=max(vx,b);
	if(l<=b) vx=max(vx,a);
	if(l>a && l>b)
	{
		if(vx>a) vx=a;
		if(vx>b) vx=b;
	}
	if(vx>l) vx=l;
	
	if(vx<=0)
		printf("My poor head =(\n");
	else
		printf("%.9lf\n",vx);
		
		
}

bool input()
{
	int aa,bb,ll;
	s(aa); s(bb); s(ll);
	a=aa;
	b=bb;
	l=ll;
	//sf(a); sf(b); sf(l);
	return true;
}


int main()
{
	preprocess();
	int T=1;
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}