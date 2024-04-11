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
#define fillbig(a,m,v) fill((void*)a,(void*)a+m,v)
#define ALL(a) (a).begin(),(a).end()
#define Inf ((int)1e9+(int)1e8+(int)1e7)
#define INF ((long long)1e18+(long long)1e17+(long long)1e16)
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
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define MASK(a) (1<<(a))
#define MASKX(x,a) ((x)<<(a))
#define BIT(a,b) ((a>>b)&1)
#define cddx(a) priority_queue<a >
#define cxdd(a) priority_queue<a,vector<a >,greater<a > >
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

const int N=1007;
pii gz[N][N];
int hvo=0;
int owz;
int n;
int dp[2][N][N],fx[2][N][N];
const char dr[3]="DR";

int main()
{
	scanf("%d",&n);
	int ina,gs2,gs5;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&ina);
			if(!ina)
			{
				hvo=1;
				owz=j;
				gz[i][j]=mp(1,1);
			}
			else
			{
				gs2=0;
				gs5=0;
				for(;ina%2==0;gs2++,ina/=2);
				for(;ina%5==0;gs5++,ina/=5);
				gz[i][j]=mp(gs2,gs5);
			}
		}
	for(int i=2;i<=n;i++)
		dp[0][0][i]=dp[0][i][0]=dp[1][0][i]=dp[1][i][0]=Inf;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			dp[0][i][j]=min(dp[0][i-1][j],dp[0][i][j-1])+gz[i][j].first;
			fx[0][i][j]=dp[0][i][j-1]<dp[0][i-1][j];
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			dp[1][i][j]=min(dp[1][i-1][j],dp[1][i][j-1])+gz[i][j].second;
			fx[1][i][j]=dp[1][i][j-1]<dp[1][i-1][j];
		}
	int mind=dp[1][n][n]<dp[0][n][n];
	if(hvo&&dp[mind][n][n])
	{
		puts("1");
		for(int i=2;i<=owz;i++)printf("R");
		for(int j=2;j<=n;j++)printf("D");
		for(int i=owz+1;i<=n;i++)printf("R");
		return 0;
	}
	vector<int> out;
	for(int i=n,j=n;i!=1||j!=1;)
	{
		out.push_back(fx[mind][i][j]);
		if(fx[mind][i][j]==0)i--;
		else j--;
	}
	printf("%d\n",dp[mind][n][n]);
	for(int i=SZ(out)-1;i>=0;i--)
		printf("%c",dr[out[i]]);
	return 0;
}