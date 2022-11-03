/**********************************************************
 * zxf
 * 
 * 
 * 
 * 
 * 
 * Time used
 * Memory used
 **********************************************************/
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define LL long long
#define pb push_back
#define pob pop_back
#define mp make_pair
#define FILL(a,v) memset((void*)a,v,sizeof(a))
#define FILL0(a) FILL(a,0)
#define FILL1(a) FILL(a,-1)
#define ALL(a) (a).begin(),(a).end()
#define Inf 1e9
#define Mod 1000000007
#define foreach(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define FOR(i,x) for(int i=0;i<x;i++)
#define RFOR(i,x) for(int i=x-1;i>=0;i--)
#define FFOR(i,a,b) for(int i=a;i<b;i++)
#define FRFOR(i,a,b) for(int i=a-1;i>=b;i--)
#define SZ(a) ((int)(a).size())
#define FI first
#define SE second
#define OVER(a) return puts(a),0
#define fastio ios::sync_with_stdio(0)
#define filei(f) freopen(f,"r",stdin)
#define fileo(f) freopen(f,"w",stdout)
#define MASK(a) (1<<(a))
#define MASKX(x,a) ((x)<<(a))
#define BIT(a,b) ((a>>b)&1)
using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int Uint;
typedef long long INT;
typedef pair<INT,INT> PII;
typedef stringstream sst;
typedef istringstream iss;
typedef vector<int> vint;
typedef vector<INT> VINT;
typedef vector<pii> vpii;
typedef vector<PII> VPII;
typedef priority_queue<int> pqi;
typedef priority_queue<INT> PQI;
typedef priority_queue<pii> pqp;
typedef priority_queue<PII> PQP;
typedef priority_queue<int,vint,greater<int> > xqi;
typedef priority_queue<INT,VINT,greater<INT> > XQI;
typedef priority_queue<pii,vpii,greater<pii> > xqp;
typedef priority_queue<PII,VPII,greater<PII> > XQP;

int a[155][155];
int b[155][155];
int an,am,bn,bm,x,y,maxn=0,maxx,maxy;

int main()
{
	scanf("%d%d",&an,&am);
	for(int i=0;i<an;i++)
		for(int j=0;j<am;j++)
			scanf("%1d",&a[i+50][j+50]);
	scanf("%d%d",&bn,&bm);
	for(int i=0;i<bn;i++)
		for(int j=0;j<bm;j++)
			scanf("%1d",&b[i+50][j+50]);
	for(x=-50;x<50;x++)
		for(y=-50;y<50;y++)
		{
			int cnt=0;
			for(int i=0;i<50;i++)
				for(int j=0;j<50;j++)
					if(a[i+50][j+50]&&b[i+x+50][j+y+50])cnt++;
			if(cnt>maxn)maxn=cnt,maxx=x,maxy=y;
		}
	printf("%d %d\n",maxx,maxy);
	return 0;
}