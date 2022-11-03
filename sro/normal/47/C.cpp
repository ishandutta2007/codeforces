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
#define inpos OVER("Impossible")
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

string s[6];
char out[107][107];
vector<int> szs;
const int n=6;
int f11=-1,f12=-1,f13=-1,f21=-1,f22=-1,f23=-1;

/*
1aaa1...
b...c...
b...c...
1ddd1dd1
....c..e
....c..e
....1ff1
*/

bool cdyx(string a,string b)
{
	if(SZ(a)<SZ(b))return 1;
	if(SZ(a)>SZ(b))return 0;
	if(a>b)return 1;
	if(a<b)return 0;
	return 0;
}

bool vct___cmp(vector<string> a,vector<string> b)
{
	if(!SZ(a))return 0;
	if(!SZ(b))return 1;
	for(int i=0;i<min(SZ(a),SZ(b));i++)
		if(a[i]<b[i])return 1;
		else if(a[i]>b[i])return 0;
	return 0;
}

vector<string> ans,aans;

int main()
{
	cin>>s[0]>>s[1]>>s[2]>>s[3]>>s[4]>>s[5];
	sort(s,s+6);
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			for(int k=0;k<6;k++)
				for(int l=0;l<6;l++)
					for(int a=0;a<6;a++)
						for(int b=0;b<6;b++)
							if(i!=j&&i!=k&&i!=l&&i!=a&&i!=b&&j!=k&&j!=l&&j!=a&&j!=b&&k!=l&&k!=a&&k!=b&&l!=a&&l!=b&&a!=b)
							{
								if(SZ(s[i])+SZ(s[a])!=SZ(s[k])+1)
									continue;
								if(SZ(s[j])+SZ(s[b])!=SZ(s[l])+1)
									continue;
								if(s[i][0]!=s[j][0])continue;
								if(s[i][SZ(s[i])-1]!=s[l][0])continue;
								if(s[j][SZ(s[j])-1]!=s[k][0])continue;
								if(s[l][SZ(s[j])-1]!=s[k][SZ(s[i])-1])continue;
								if(s[l][SZ(s[l])-1]!=s[a][0])continue;
								if(s[b][0]!=s[k][SZ(s[k])-1])continue;
								if(s[a][SZ(s[a])-1]!=s[b][SZ(s[b])-1])continue;
								FILL0(out);
								aans.clear();
								for(int aa=0;aa<SZ(s[i]);aa++)out[aa][0]=s[i][aa];
								for(int aa=0;aa<SZ(s[j]);aa++)out[0][aa]=s[j][aa];
								for(int aa=0;aa<SZ(s[k]);aa++)out[aa][SZ(s[j])-1]=s[k][aa];
								for(int aa=0;aa<SZ(s[l]);aa++)out[SZ(s[i])-1][aa]=s[l][aa];
								for(int aa=0;aa<SZ(s[a]);aa++)out[SZ(s[i])-1+aa][SZ(s[l])-1]=s[a][aa];
								for(int aa=0;aa<SZ(s[b]);aa++)out[SZ(s[k])-1][SZ(s[j])-1+aa]=s[b][aa];
								for(int i=0;i<SZ(s[k]);i++)
									for(int j=0;j<SZ(s[l]);j++)
										if(!out[i][j])out[i][j]='.';
								for(int i=0;i<SZ(s[k]);i++)
									aans.push_back(out[i]);
								if(vct___cmp(aans,ans))ans=aans;
							}
	if(!SZ(ans))inpos;
	for(int i=0;i<SZ(ans);i++)
		cout<<ans[i]<<endl;
	return 0;
}