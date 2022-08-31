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
double ax,ay,az,bx,by,bz,R;
int n;
double ox[1000],oy[1000],oz[1000],rr[1000],m[1000];
double spkx[1000][100],spky[1000][100],spkz[1000][100];


pair<bool,double> solve(double a,double b,double c)
{
	double det=b*b-4*a*c;
	if(det<0) return mp(false,0.0);
	det = sqrt(det);
	double r1 = (-b+det)/(a+a);
	double r2 = (-b-det)/(a+a);
	if(r1<0 && r2<0) return mp(false,0.0);
	if(r1<0) return mp(true,r2);
	if(r2<0) return mp(true,r1);
	return mp(true,min(r1,r2));
}

pair<bool,double> bomb(double px,double py,double pz,double r)
{
	double a = (bx*bx + by*by + bz*bz);
	double b = 2*(ax*bx+ay*by+az*bz - px*(bx) - py*(by) - pz*(bz));
	double c = (px*px+py*py+pz*pz)+(ax*ax+ay*ay+az*az)-r*r-2*(px*ax+py*ay+pz*az);
	return solve(a,b,c);
}


void preprocess()
{

}

void solve()
{
	bool hit=false;
	double mintime = 1e24;
	pair<bool,double> temp;
	for(int i=0;i<n;i++)
	{
		temp=bomb(ox[i],oy[i],oz[i],rr[i]+R);
		if(temp.first)
		{
			hit=true;
			mintime=min(mintime,temp.second);
		}
		
		for(int j=0;j<m[i];j++)
		{
			temp=bomb(ox[i]+spkx[i][j],oy[i]+spky[i][j],oz[i]+spkz[i][j],R);
			if(temp.first)
			{
				hit=true;
				mintime=min(mintime,temp.second);
			}
		}
	}
	
	if(hit)
		printf("%.9lf\n",mintime);
	else
		printf("-1\n");
}

bool input()
{
	sf(ax); sf(ay); sf(az); sf(bx); sf(by); sf(bz); sf(R);
	s(n);
	for(int i=0;i<n;i++)
	{
		sf(ox[i]); sf(oy[i]); sf(oz[i]); sf(rr[i]); sf(m[i]);
		for(int j=0;j<m[i];j++)
		{
			sf(spkx[i][j]);
			sf(spky[i][j]);
			sf(spkz[i][j]);
		}
	}
	
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