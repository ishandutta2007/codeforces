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
#define eatreturn getline(cin,RETURN_EATER_IDE)
using namespace std;
string RETURN_EATER_IDE;
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

int n;
string s;
map<string,vector<string> > func;
map<string,char> valu;

void getfunc()
{
	getline(cin,s);
	int mode=0;
	string nams,lss;
	//mode:0.2.eat space;1.eat void;3.get name;4.get vals
	for(int i=0;i<SZ(s);i++)
	{
		if(mode==0&&s[i]!=' ')
			mode=1;
		if(mode==1&&!isalpha(s[i]))mode=2;
		if(mode==2&&s[i]!=' ')
			mode=3;
		if(mode==3&&!isalnum(s[i]))mode=4;
		if(mode==3)nams+=s[i];
		if(mode==4&&isalnum(s[i]))
		{
			lss+=s[i];
			if(s[i]=='T')i++;
			if(s[i]=='i')i+=3;
			if(s[i]=='d')i+=6;
			if(s[i]=='s')i+=6;
		}
	}
	func[nams].pb(lss);
}

void getval()
{
	getline(cin,s);
	int mode=0;
	string name;
	char lss;
	//mode:0.eat space;1.get name
	for(int i=0;i<SZ(s);i++)
	{
		if(mode==1&&s[i]!=' ')name+=s[i];
		if(mode==0&&s[i]!=' ')
		{
			lss=s[i];
			if(s[i]=='i')i+=3;
			if(s[i]=='d')i+=6;
			if(s[i]=='s')i+=6;
			mode=1;
		}
	}
	valu[name]=lss;
}

void getuse()
{
	getline(cin,s);
	string name;
	string vals,valname;
	int mode=0;
	//mode:0.eat space;1.get name;2.get vals;3.get vspace
	for(int i=0;i<SZ(s);i++)
	{
		if(mode==0&&s[i]!=' ')mode=1;
		if(mode==1&&!isalnum(s[i]))mode=3;
		if(mode==3&&isalnum(s[i]))mode=2;
		if(mode==2&&!isalnum(s[i]))
		{
			mode=3;
			vals+=valu[valname];
			valname="";
		}
		if(mode==1)name+=s[i];
		if(mode==2)valname+=s[i];
	}
	string ss;
	int cnt=0;
	for(int i=0;i<SZ(func[name]);i++)
	{
		ss=func[name][i];
		if(SZ(vals)!=SZ(ss))continue;
		int can=1;
		for(int i=0;i<SZ(ss);i++)
			if(ss[i]!='T'&&ss[i]!=vals[i])
			{
				can=0;
				break;
			}
		cnt+=can;
	}
	printf("%d\n",cnt);
}

int main()
{
	scanf("%d",&n);
	eatreturn;
	for(int i=0;i<n;i++)getfunc();
	scanf("%d",&n);
	eatreturn;
	for(int i=0;i<n;i++)getval();
	scanf("%d",&n);
	eatreturn;
	for(int i=0;i<n;i++)getuse();
	return 0;
}