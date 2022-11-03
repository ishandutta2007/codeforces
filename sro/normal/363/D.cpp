/*

short-32768~32767
unsigned short0~65535
int-2147483648~2147483647
uint0~4294967295
INT-9223372036854775808~9223372036854775807
UINT0~18446744073709551615
float-3.4e383.4e386~7
double-1.7e308~1.7e30815~16
ldouble-1.2e4932~1.2e493218~19
*/
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
using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int Uint;
typedef long long INT;
typedef pair<INT,INT> PII;

INT n,m,g;
INT ren[100007],dox[100007];

INT xin(INT peo)
{
	INT xgy=0;
	for(INT i=0;i<peo;i++)
	{
		if(ren[i]<dox[peo-i-1])
			xgy+=dox[peo-i-1]-ren[i];
	}
	if(xgy<=g)return xgy;
	else return -1;
}

bool dayuornot(INT a,INT b){return a>b;}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&g);
	for(INT i=0;i<n;i++)
		scanf("%I64d",&ren[i]);
	sort(ren,ren+n,dayuornot);
	for(INT i=0;i<m;i++)
		scanf("%I64d",&dox[i]);
	sort(dox,dox+m);
	INT least=-1,most=min(n,m)+1,gff=0;
	while(most-least>1)
	{
		INT mid=(most+least)/2;
		INT b=xin(mid);
		if(b!=-1)
		{
			least=mid;
		}
		else most=mid;
	}
	for(INT i=0;i<least;i++)gff+=dox[i];
	gff-=g;
	if(gff<0)gff=0;
	printf("%I64d %I64d\n",least,gff);
	return 0;
}