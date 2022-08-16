/*
PROG: Industrial Nim, CodeForces#15.C
LANG: C++
ID: AnilKishore (RedAnt/FlyingAnt)
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;

#define INF 100000000
#define PB push_back
#define MP make_pair
#define FILL(v,x) memset(v,x,sizeof(v))
#define ALL(v) (v).begin(),(v).end()
#define SI(x) scanf("%d",&x)
#define MX 100005

int N;

/*
LL play(LL x, LL m)
{
	LL r = 0;
	for(int bp=0;bp<=62;bp++)
	{
		LL ones = 0;
		LL pw = (1ll<<bp), pw2 = pw*2;
		LL px = x%pw2, pxm = (x+m-1)%pw2;
		LL afterx = min( pw , pw2 - px ), beforexm = max( 0ll , pxm - pw + 1 );
		if( x/pw2 == (x+m-1)/pw2 ) ones = (px<pw) ? ( pxm<pw?0:beforexm ) : (pxm-px+1);
		else ones = afterx + beforexm;

		if(ones%2==1) r |=(1ll<<bp);
	}
	return r;
}
*/


LL Ones(LL x,int bp)
{
	if(x<1ll) return 0;
	LL pw = (1ll<<bp), pw2 = pw*2ll;
	return (x/pw2)*pw + max( 0ll , (x%pw2) - pw + 1 );
}


LL play(LL x, LL m)
{
	LL r = 0;
	
	for(int bp=0;bp<=62;bp++)
	{
		LL ones = Ones(x+m-1,bp) - Ones(x-1,bp);
		if(ones%2==1) r|=(1ll<<bp);
	}

	return r;
}


int main()
{
	int i,j,k;
	LL g=0,x,m;

	cin>>N;
	for(i=0;i<N;i++)
	{
		cin>>x>>m;
		g^=play(x,m);
	}

	puts( (g>0ll) ?"tolik":"bolik");

	return 0;
}