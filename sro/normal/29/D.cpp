/*****************
 *   I<3   C++   *
 *  IWANT ANYAC  *
 * ILOVEPROGRAM! *
 *IT'SINTERESTING*
 * ILOVEPROGRAM! *
 *  INCONTESTS   *
 *   GETSCORE    *
 *    ACCODE     *
 *     LETS      *
 *      GO       *
 *Written by:    *
 *    charlieyan *
 *****************/
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <locale>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <wctype.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <map>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <cwchar>
#include <cwctype>
#include <complex.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <tgmath.h>
#include <numeric>
#include <list>
#define LL long long
#define pb push_back
#define pob pop_back
#define mp make_pair
#define FILL(a,v) memset((void*)a,v,sizeof(a))
#define FILL0(a) FILL(a,0)
#define FILL1(a) FILL(a,-1)
#define FILLBIG(a) FILL(a,0x7f)
#define ALL(a) (a).begin(),(a).end()
#define Inf ((int)0x7f7f7f7f)
#define INF ((long long)0x7f7f7f7f7f7f7f7f)
#define Mod 1000000007
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
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
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define MASK(a) (1<<(a))
#define MASKX(x,a) ((x)<<(a))
#define BIT(a,b) ((a>>b)&1)
#define cddx(a) priority_queue<a >
#define cxdd(a) priority_queue<a,vector<a >,greater<a > >
#define deval(a) {cerr<<#a<<" = "<<a<<endl;}
#define reg register
using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int uint;
typedef long long INT;
typedef long double ldouble;
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

int n,k;
vector<int> nei[307];
vector<int> path[307];
vector<int> paa;
vpii pas;
int a[307],fa[307];
map<pii,int> pa;
int xt[306];

void dfsp(int now,int syg)
{
	paa.pb(now);
	for(int i=0;i<SZ(nei[now]);i++)
		if(nei[now][i]!=syg)
			dfsp(nei[now][i],now);
	path[now]=paa;
	paa.pob();
}

int xont(int aa)
{
	for(int i=0;i<min(SZ(path[a[aa]]),SZ(path[a[aa+1]]));i++)
		if(path[a[aa]][i]!=path[a[aa+1]][i])return i-1;
	return min(SZ(path[a[aa]]),SZ(path[a[aa+1]]))-1;
}

vector<int> road;
int cs[306];

bool solr()
{
	road=path[a[1]];
	road.pob();
	for(int i=0;i<SZ(path[a[1]])-1;i++)cs[pa[mp(path[a[1]][i],path[a[1]][i+1])]]++;
	for(int i=1;i<k;i++)
	{
		for(int j=SZ(path[a[i]])-1;j>xt[i];j--)
		{road.pb(path[a[i]][j]);cs[pa[mp(path[a[i]][j],path[a[i]][j-1])]]++;}
		for(int j=xt[i];j<SZ(path[a[i+1]])-1;j++)
		{road.pb(path[a[i+1]][j]);cs[pa[mp(path[a[i+1]][j],path[a[i+1]][j+1])]]++;}
	}
	for(int j=SZ(path[a[k]])-1;j>0;j--)
	{road.pb(path[a[k]][j]);cs[pa[mp(path[a[k]][j],path[a[k]][j-1])]]++;}
	road.pb(1);
	for(int i=0;i<306;i++)if(cs[i]>2)return false;
	return true;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		nei[u].pb(v);
		nei[v].pb(u);
		pas.pb(mp(u,v));
		pa[mp(u,v)]=pa[mp(v,u)]=i;
	}
	while(scanf("%d",&a[++k])!=EOF)
		fa[a[k]]=k;
	k--;
	dfsp(1,-1);
	int cur;
	for(int i=1;i<k;i++)xt[i]=xont(i);
	if(!solr())OVER("-1");
	for(int i=0;i<SZ(road);i++)printf("%d ",road[i]);
	return 0;
}