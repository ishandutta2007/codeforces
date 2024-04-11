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
#define dearr(be,en) {cerr<<#be;cerr<<" = {";for(auto i=be;i!=en;i++)cerr<<' '<<*i;cerr<<" }\n";}
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

vector<int> nei[3007];
int n,m;
int dist[3007][3007];
int mxfrm[3007][3],mxto[3007][3];

void bfs(int start)
{
	FILL1(dist[start]);
	queue<int> q,bs;
	q.push(start);
	bs.push(0);
	dist[start][start]=0;
	while(!q.empty())
	{
		int qq=q.front(),bb=bs.front();
		q.pop();bs.pop();
		for(int i:nei[qq])
			if(dist[start][i]==-1)
			{
				q.push(i);
				bs.push(bb+1);
				dist[start][i]=bb+1;
			}
	}
}

void gengxin(int a,int b)
{
	if(dist[a][b]>dist[a][mxfrm[a][0]])
	{
		mxfrm[a][2]=mxfrm[a][1];
		mxfrm[a][1]=mxfrm[a][0];
		mxfrm[a][0]=b;
	}
	else if(dist[a][b]>dist[a][mxfrm[a][1]])
	{
		mxfrm[a][2]=mxfrm[a][1];
		mxfrm[a][1]=b;
	}
	else if(dist[a][b]>dist[a][mxfrm[a][2]])
	{
		mxfrm[a][2]=b;
	}
	if(dist[a][b]>dist[mxto[b][0]][b])
	{
		mxto[b][2]=mxto[b][1];
		mxto[b][1]=mxto[b][0];
		mxto[b][0]=a;
	}
	else if(dist[a][b]>dist[mxto[b][1]][b])
	{
		mxto[b][2]=mxto[b][1];
		mxto[b][1]=a;
	}
	else if(dist[a][b]>dist[mxto[b][2]][b])
	{
		mxto[b][2]=a;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		nei[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		bfs(i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			gengxin(i,j);
	int maxsum=0,maxa,maxb,maxc,maxd;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)if(i!=j&&dist[i][j]!=-1)
			for(int k=0;k<3;k++)
				for(int l=0;l<3;l++)
				{
					int ii=mxto[i][k],jj=mxfrm[j][l];
					if(ii!=0&&jj!=0&&ii!=jj&&i!=jj&&j!=ii&&i!=ii&&j!=jj&&dist[ii][i]!=-1&&dist[j][jj]!=-1&&dist[ii][i]+dist[i][j]+dist[j][jj]>maxsum)
					{
						maxsum=dist[ii][i]+dist[i][j]+dist[j][jj];
						maxa=ii;
						maxb=i;
						maxc=j;
						maxd=jj;
					}
				}
	printf("%d %d %d %d\n",maxa,maxb,maxc,maxd);
	return 0;
}