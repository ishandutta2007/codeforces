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
int lo[10][10];
int hi[10][10];
int ac[10][10];
int n;

int lim[10];


int flo[10][10];
int thru[10][10];

void preprocess()
{

}

void solve()
{
	int bestf=INF;
	int bestc=0;
	int pipes = (n*(n-1))/2;

	for(int i=0;i<n;i++)
		lim[i] = min( 5*i, 5*(n-1-i));
	lim[0] = 5*(n-1);
	lim[n-1]=lim[0];
		
	int basef = lo[0][n-1];
	int basec = basef*basef + ac[0][n-1];
		


	fill(thru,0);
	
	flo[0][5]=lo[0][5];
	for(int a1=lo[0][1];a1<=hi[0][1];a1++)
	for(int a2=lo[0][2];a2<=hi[0][2];a2++)
	for(int a3=lo[0][3];a3<=hi[0][3];a3++)
	for(int a4=lo[0][4];a4<=hi[0][4];a4++)
	{
		int fuel=a1+a2+a3+a4+lo[0][5];
		


		flo[0][1]=a1;
		flo[0][2]=a2;
		flo[0][3]=a3;
		flo[0][4]=a4;
		thru[0][1]=a1;
		thru[0][2]=a2;
		thru[0][3]=a3;
		thru[0][4]=a4;
		
		if(n==2)
		if(fuel>bestf) continue;
		else
		{
			int cost=0;
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
					if(flo[i][j]>0)
						cost += flo[i][j]*flo[i][j] + ac[i][j];
			
			if(fuel<bestf || (fuel==bestf && cost>bestc))
			{
				bestf=fuel;
				bestc=cost;
			}
			continue;
		}		

	for(int b2=lo[1][2];b2<=hi[1][2] && b2			<=thru[0][1];b2++)
	for(int b3=lo[1][3];b3<=hi[1][3] && b2+b3		<=thru[0][1];b3++)
	for(int b4=lo[1][4];b4<=hi[1][4] && b2+b3+b4	<=thru[0][1];b4++)
	for(int b5=lo[1][5];b5<=hi[1][5] && b2+b3+b4+b5	<=thru[0][1];b5++)
	{


		if(thru[0][1] != b2+b3+b4+b5) continue;
		flo[1][2]=b2;
		flo[1][3]=b3;
		flo[1][4]=b4;
		flo[1][5]=b5;
		thru[1][2]=thru[0][2]+b2;
		thru[1][3]=thru[0][3]+b3;
		thru[1][4]=thru[0][4]+b4;
		
				if(n==3)
		if(fuel>bestf) continue;
		else
		{
			int cost=0;
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
					if(flo[i][j]>0)
						cost += flo[i][j]*flo[i][j] + ac[i][j];
			
			if(fuel<bestf || (fuel==bestf && cost>bestc))
			{
				bestf=fuel;
				bestc=cost;
			}
			continue;
		}

	for(int c3=lo[2][3];c3<=hi[2][3] && c3		<=thru[1][2];c3++)
	for(int c4=lo[2][4];c4<=hi[2][4] && c3+c4	<=thru[1][2];c4++)
	for(int c5=lo[2][5];c5<=hi[2][5] && c3+c4+c5<=thru[1][2];c5++)
	{

		if(thru[1][2] != c3+c4+c5) continue;
		flo[2][3]=c3;
		flo[2][4]=c4;
		flo[2][5]=c5;
		thru[2][3]=thru[1][3]+c3;
		thru[2][4]=thru[1][4]+c4;
		
				if(n==4)
		if(fuel>bestf) continue;
		else
		{
			int cost=0;
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
					if(flo[i][j]>0)
						cost += flo[i][j]*flo[i][j] + ac[i][j];
			
			if(fuel<bestf || (fuel==bestf && cost>bestc))
			{
				bestf=fuel;
				bestc=cost;
			}
			continue;
		}
	
		
	for(int d4=lo[3][4];d4<=hi[3][4] && d4		<=thru[2][3];d4++)
	for(int d5=lo[3][5];d5<=hi[3][5] && d4+d5	<=thru[2][3];d5++)
	{
		
		
		if(thru[2][3] != d4+d5) continue;
		flo[3][4]=d4;
		flo[3][5]=d5;
		thru[3][4]=thru[2][4]+d4;
		
				if(n==5)
		if(fuel>bestf) continue;
		else
		{
			int cost=0;
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
					if(flo[i][j]>0)
						cost += flo[i][j]*flo[i][j] + ac[i][j];
			
			if(fuel<bestf || (fuel==bestf && cost>bestc))
			{
				bestf=fuel;
				bestc=cost;
			}
			continue;
		}

	for(int e5=lo[4][5];e5<=hi[4][5] && e5	<=thru[3][4];e5++)
	{
		if(thru[3][4] != e5) continue;
		flo[4][5]=e5;

		if(fuel>bestf) continue;
		else
		{
			int cost=0;
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++)
					if(flo[i][j]>0)
						cost += flo[i][j]*flo[i][j] + ac[i][j];
			
			if(fuel<bestf || (fuel==bestf && cost>bestc))
			{
				bestf=fuel;
				bestc=cost;
			}
			continue;
		}
	}
	}
	}
	}
	}
	
	if(bestf<INF/2)
		printf("%d %d\n",bestf,bestc);
	else
		printf("-1 -1\n");
				
	
		
		

	

	
		
}

bool input()
{
	s(n);
	int x,y;
	fill(lo,0);
	fill(hi,0);
	fill(ac,0);

		
	for(int i=0;i<(n*(n-1))/2;i++)
	{
		s(x); s(y);
		x--; y--;
		s(lo[x][y]);
		s(hi[x][y]);
		s(ac[x][y]);
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