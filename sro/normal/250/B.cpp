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
#define Inf (2147483647-214748+3647)
#define INF ((long long)1e18+(long long)1e17+(long long)1e16)
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

string num[8];
int n;
int duiy[256];
string s;

void print()
{
	cout<<num[0]<<':'<<num[1]<<':';
	cout<<num[2]<<':'<<num[3]<<':';
	cout<<num[4]<<':'<<num[5]<<':';
	cout<<num[6]<<':'<<num[7]<<endl;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<10;i++)duiy[48+i]=i;
	for(int i=10;i<16;i++)duiy[87+i]=i;
	for(int iiii=0;iiii<n;iiii++)
	{
		cin>>s;
		for(int i=0;i<8;i++)num[i]="";
		if(s=="::")
		{
			puts("0000:0000:0000:0000:0000:0000:0000:0000");
			continue;
		}
		int i=0;
		int frnt=0,back=0,zhong=-1;
		if(s.find("::")!=-1)zhong=s.find("::");
		if(zhong==-1)
		{
			for(int i=0,j=0;i<SZ(s);i++)
				if(s[i]!=':')
					num[j]=num[j]+s[i];
				else
					j++;
			for(int i=0;i<8;i++)
				while(SZ(num[i])<4)num[i]="0"+num[i];
			print();
		}
		else
		{
			for(int i=0;i<zhong;i++)
				if(s[i]!=':')num[frnt]+=s[i];
				else frnt++;
			frnt++;
			for(int i=zhong+2;i<SZ(s);i++)
				if(s[i]==':')back++;
			back++;
			int cnbk=0;
			for(int i=zhong+2;i<SZ(s);i++)
				if(s[i]!=':')num[8-back+cnbk]+=s[i];
				else cnbk++;
			for(int i=0;i<8;i++)
				while(SZ(num[i])<4)num[i]="0"+num[i];
			print();
		}
	}
	return 0;
}