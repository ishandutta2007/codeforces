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

vpii nei[5007],tpnei[5007];
vint tpsrt;
int lgl[5007],intpsrt[5007],snx[5007];
int res[5007][5007];

void dfs(int th)
{
	lgl[th]=1;
	for(pii i:nei[th])
		if(!lgl[i.first])
			dfs(i.first);
	tpsrt.push_back(th);
}

int n,m,t,mint[5007][5007];

int main()
{
	scanf("%d%d%d",&n,&m,&t);
	for(int i=0;i<m;i++)
	{
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		a--,b--;
		nei[a].push_back(mp(b,w));
	}
	for(int i=0;i<n;i++)
		if(!lgl[i])
			dfs(i);
	reverse(tpsrt.begin(),tpsrt.end());
	for(int i=0;i<n;i++)
		intpsrt[tpsrt[i]]=i;
	for(int i=0;i<n;i++)
		for(pii j:nei[i])
		{
			int v1=intpsrt[i];
			int v2=intpsrt[j.first];
			tpnei[v1].push_back(mp(v2,j.second));
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			mint[i][j]=t+1;
	int start=intpsrt[0];
	mint[start][0]=0;
	res[start][0]=-1;
	for(int i=0;i<n;i++)
		for(pii j:tpnei[i])
		{
			int js=j.second,jf=j.first;
			for(int k=0;k<=i;k++)
				if(mint[jf][k+1]>mint[i][k]+js)
				{
					mint[jf][k+1]=mint[i][k]+js;
					res[jf][k+1]=i;
				}
		}
	int last=intpsrt[n-1];
	int go=-1;
	for(int i=0;i<n;i++)
		if(mint[last][i]<=t)go=i;
	snx[go]=tpsrt[last];
	for(int i=go-1;i>=0;i--)
	{
		last=res[last][i+1];
		snx[i]=tpsrt[last];
	}
	printf("%d\n",go+1);
	for(int i=0;i<=go;i++)
		printf("%d%c",snx[i]+1,i==go?'\n':' ');
	return 0;
}