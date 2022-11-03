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
#define prtime eprintf("\n\nTime used: %dms",clock());
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

INT X=19260817,M1=1887415157,M2=1428943841;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
char ditu[16][16];
int n,m;

struct snake
{
	int s,x[10],y[10];
	inline bool canmove(int where)
	{
		int xx=x[1]+dx[where],yy=y[1]+dy[where];
		if(xx<0||xx>=n||yy<0||yy>=m)return false;
		if(ditu[xx][yy]=='#')return false;
		for(int i=2;i<s;i++)if(xx==x[i]&&yy==y[i])return false;
		return true;
	}
	inline void move(int where)
	{
		for(int i=s;i>1;i--)x[i]=x[i-1],y[i]=y[i-1];
		x[1]+=dx[where];
		y[1]+=dy[where];
	}
	inline INT hash()
	{
		INT s1=0,s2=0;
		for(int i=1;i<=s;i++)
			s1=(s1*X+x[i])%M1;
		for(int i=1;i<=s;i++)
			s2=(s2*X+y[i])%M2;
		return (s1<<32)+s2;
	}
	inline bool win()
	{
		if(ditu[x[1]][y[1]]=='@')return 1;
		else return 0;
	}
};

snake start;
set<INT> came;
queue<snake> q;
queue<int> bs;

int bfs()
{
	came.insert(start.hash());
	q.push(start);
	bs.push(0); 
	while(!q.empty())
	{
		snake sn=q.front();q.pop();
		int bb=bs.front();bs.pop();
		for(int i=0;i<4;i++)if(sn.canmove(i))
		{
			snake ssn=sn;
			ssn.move(i);
			if(came.count(ssn.hash()))continue;
			came.insert(ssn.hash());
			q.push(ssn);
			bs.push(bb+1);
			if(ssn.win())return bb+1;
		}
	}
	return -1;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",ditu[i]);
		for(int j=0;j<m;j++)
			if(isdigit(ditu[i][j]))
				start.x[ditu[i][j]-'0']=i,start.y[ditu[i][j]-'0']=j,start.s=max(ditu[i][j]-'0',start.s);
	}
	printf("%d\n",bfs());
	return 0;
}