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

int n,a[10],b[10];
set<int> cnuse;
int need=0;
int anw[1000007],anx[1000007],any[1000007],anz[1000007],ans;
int good[256],mask[256];
int wei[256][4],weis[256];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		need|=MASK(a[i]);
		b[a[i]]=1;
	}
	if(n>6)OVER("0");
	for(int i=0;i<256;i++)
	{
		good[i]=1;
		int x=i;
		mask[i]=0;
		while(x)
		{
			wei[i][weis[i]++]=x%10;
			if(!b[x%10])good[i]=0;
			mask[i]|=MASK(x%10);
			x/=10;
		}
		if(i==0&&!b[0])good[i]=0;
		if(i==0)
		{
			wei[i][weis[i]++]=0;
			mask[i]|=MASK(0);
		}
	}
	int q[20];
	for(int i=0;i<256;i++)if(good[i])
		for(int j=0;j<256;j++)if(good[j])
			for(int k=0;k<256;k++)if(good[k])
				if((mask[i]|mask[j]|mask[k])==need)
					for(int l=0;l<256;l++)if(good[l])
					{
						int u=0;
						for(int x=weis[i]-1;x>=0;x--)q[u++]=wei[i][x];
						for(int x=weis[j]-1;x>=0;x--)q[u++]=wei[j][x];
						for(int x=weis[k]-1;x>=0;x--)q[u++]=wei[k][x];
						for(int x=weis[l]-1;x>=0;x--)q[u++]=wei[l][x];
						bool can=1;
						for(int i=0;i<=u/2;i++)if(q[i]!=q[u-i-1])can=0;
						if(can)
						{
							anw[ans]=i;
							anx[ans]=j;
							any[ans]=k;
							anz[ans]=l;
							ans++;
						}
					}
	printf("%d\n",ans);
	for(int i=0;i<ans;i++)
		printf("%d.%d.%d.%d\n",anw[i],anx[i],any[i],anz[i]);
	return 0;
}