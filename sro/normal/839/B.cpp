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
 *****************/
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

int n,k,a[100007];
int have[10050][5],hzz=0;
int cn4,cn2,cn1,sum=0;

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d",a+i);
		sum+=a[i];
		while(a[i]>=4)cn4++,a[i]-=4;
		if(a[i]>=2)cn2++,a[i]-=2;
		if(a[i]>=1)cn1++,a[i]-=1;
	}
	if(sum+cn1>n*8)OVER("NO");
	int c1=hzz,c2=hzz,c3=hzz,c4=hzz;
	int i;
	for(i=0;c2<n&&i<cn4;c2++,c3++,i++)
		have[c2][2]=have[c3][3]=1;
	for(;c1<n&&i<cn4;c1++,c4++,i++)
		have[c1][1]=have[c4][4]=1;
	for(;i<cn4;i++)cn2+=2;
	for(i=0;c1<n&&i<cn2;c1++,i++)
		have[c1][1]=1;
	for(;c2<n&&i<cn2;c2++,i++)
		have[c2][2]=1;
	for(;c4<n&&i<cn2;c4++,i++)
		have[c4][4]=1;
	for(;i<cn2;i++)cn1+=2;
	for(i=0;c1<n&&i<cn1;c1++,i++)
		have[c1][1]=1;
	for(;c2<n&&i<cn1;c2++,i++)
		have[c2][2]=1;
	for(;c3<n&&i<cn1;c3++,i++)
		have[c3][3]=1;
	for(;c4<n&&i<cn1;c4++,i++)
		have[c4][4]=1;
	if(i!=cn1)OVER("NO");
	OVER("YES");
}