/*

                                                  
                          
                                          
                                              
                                
                          
                                                  
                    
                                          
                                    
                                                
                              
                                            
                                  
              ******************                    
              * Scan this QR   *          
            * code to join   *          
              * in the Three   *                
                  * Body ETO.      *                
              *  --ETO manager *                      
              *    Ye Wenjie   *          
            *ETO(C),1988~2018*                
            ******************                
                                            
                        
                                      
                                        
                                    
                                    
                                
                                            
                          
                                          
                          
                                      
                              
                                      

                                        E    T    O
*/
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
#include <numeric>
#include <list>
#define LL long long
#define pb push_back
#define pob pop_back
#define mp make_pair
#define FILL(a,v) memset((void*)a,v,sizeof(a))
#define FILL0(a) FILL(a,0)
#define FILL1(a) FILL(a,-1)
#define FILLBIG(a) FILL(a,0x3f)
#define ALL(a) (a).begin(),(a).end()
#define Inf ((int)0x3f3f3f3f)
#define INF ((long long)0x3f3f3f3f3f3f3f3f)
#define Mod 1000000007
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define FOR(i,x) for(int i=0;i<x;i++)
#define RFOR(i,x) for(int i=x-1;i>=0;i--)
#define FFOR(i,a,b) for(int i=a;i<b;i++)
#define FRFOR(i,a,b) for(int i=a-1;i>=b;i--)
#define SZ(a) ((int)(a).size())
#define FI first
#define SE second
#define OVER(...) return printf(__VA_ARGS__),0
#define fastio ios::sync_with_stdio(0)
#define filei(f) freopen(f,"r",stdin)
#define fileo(f) freopen(f,"w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define MASK(a) (1<<(a))
#define MASKX(x,a) ((x)<<(a))
#define BIT(a,b) (((a)>>(b))&1)
#define cddx(a) priority_queue<a >
#define cxdd(a) priority_queue<a,vector<a >,greater<a > >
#define deval(a) {cerr<<#a<<" = "<<a<<endl;}
#define dearr(be,en) {cerr<<#be;cerr<<" = {";for(auto i=be;i!=en;i++)cerr<<' '<<*i;cerr<<" }\n";}
#define reg register
#define prtime eprintf("\n\nTime used: %dms\n",clock());
#define PI 3.1415926535897932384626
#define TODEG(a) (a*180/PI)
#define y0 ykangjimutigeidiqiuyipianjingtu
#define y1 yxiaomiexuduhuanrenleiwannianankang
#define endl '\n'
//
//
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
struct fastIO
{
	inline fastIO operator>>(int& num)
	{
		num=0;
		char c=getchar();
		while(c!='-'&&(c<'0'||c>'9'))c=getchar();
		bool foo=0;
		if(c=='-')
		{
			foo=1;
			c=getchar();
		}
		while(c>='0'&&c<='9')
		{
			num=(num<<3)+(num<<1)+c-'0';
			c=getchar();
		}
		if(foo)num=-num;
		return *this;
	}
	inline fastIO operator>>(INT& num)
	{
		num=0;
		char c=getchar();
		while(c!='-'&&(c<'0'||c>'9'))c=getchar();
		bool foo=0;
		if(c=='-')
		{
			foo=1;
			c=getchar();
		}
		while(c>='0'&&c<='9')
		{
			num=(num<<3)+(num<<1)+c-'0';
			c=getchar();
		}
		if(foo)num=-num;
		return *this;
	}
	inline fastIO operator>>(float& num)
	{
		scanf("%f",&num);
		return *this;
	}
	inline fastIO operator>>(double& num)
	{
		scanf("%lf",&num);
		return *this;
	}
	inline fastIO operator>>(long double& num)
	{
		scanf("%Lf",&num);
		return *this;
	}
	inline fastIO operator>>(char& num)
	{
		num=getchar();
		while(num==' '||num=='\n')num=getchar();
		return *this;
	}
	inline fastIO operator>>(char* num)
	{
		int cnt=0;
		char c=getchar();
		while(c==' '||c=='\n')c=getchar();
		while(c!=' '&&c!='\n')
		{
			num[cnt++]=c;
			c=getchar();
		}
		num[cnt]=0;
		return *this;
	}
	inline fastIO operator>>(string& num)
	{
		cin>>num;
		return *this;
	}
	inline void printInt(const int& num)
	{
		if(num<10)
		{
			putchar(num+'0');
			return;
		}
		printInt(num/10);
		putchar((num%10)+'0');
	}
	inline void printINT(const INT& num)
	{
		if(num<10)
		{
			putchar(num+'0');
			return;
		}
		printINT(num/10);
		putchar((num%10)+'0');
	}
	inline fastIO operator<<(const int& num)
	{
		if(num<0)putchar('-'),printInt(-num);
		else printInt(num);
		return *this;
	}
	inline fastIO operator<<(const INT& num)
	{
		if(num<0)putchar('-'),printINT(-num);
		else printINT(num);
		return *this;
	}
	inline fastIO operator<<(const float& num)
	{
		printf("%.10f",num);
		return *this;
	}
	inline fastIO operator<<(const double& num)
	{
		printf("%.16lf",num);
		return *this;
	}
	inline fastIO operator<<(const long double& num)
	{
		printf("%.20Lf",num);
		return *this;
	}
	inline fastIO operator<<(const char& num)
	{
		putchar(num);
		return *this;
	}
	inline fastIO operator<<(const char* num)
	{
		for(int i=0;num[i];i++)
			putchar(num[i]);
		return *this;
	}
	inline fastIO operator<<(const string& num)
	{
		cout<<num;
		return *this;
	}
}fio;
//Coded by Charlieyan
//

INT n,m;
vector<pii> nei[1000005];
INT hv[1000005],mx[1000005];
vector<INT> stk;
INT lgl[1000005];
INT llk[1000005];
INT tmc[1000005],cmt[1000005];
vector<INT> qlt[1000005];
INT blst[1000005];
INT cnqlt,djg;

void tarjan(INT now){
	stk.pb(now);
	tmc[now]=llk[now]=++djg;
	cmt[djg]=now;
	lgl[now]=1;
	for(INT i=0;i<SZ(nei[now]);i++){
		if(lgl[nei[now][i].first]==2){
			continue;
		}
		if(!lgl[nei[now][i].first]){
			tarjan(nei[now][i].first);
		}
		llk[now]=min(llk[now],llk[nei[now][i].first]);
	}
	if(tmc[now]==llk[now]){
		cnqlt++;
		while(SZ(stk)){
			INT x=stk.back();
			stk.pob();
			lgl[x]=2;
			blst[x]=cnqlt;
			qlt[cnqlt].pb(x);
			if(x==now){
				break;
			}
		}
	}
}

INT faq[100005];
vector<PII> nei2[1000005];
bool roo[1000005];
map<INT,INT> hvl[1000005];
INT dem[1000005];

INT calc(INT x){
	INT l=0,r=x+1;
	while(r-l>1){
		INT m=(l+r)>>1;
		if(m*(m+1)/2<=x){
			l=m;
		}else{
			r=m;
		}
	}
	return 1LL*x*(l+1)-faq[l];
}

void chmax(INT &a,INT b){
	if(a<b){
		a=b;
	}
}

vector<INT> px;
bool lgll[1000005];
INT dp[1000005];

void dfs2(INT now){
	if(lgll[now]){
		return;
	}
	dp[now]=0;
	lgll[now]=1;
	for(INT i=0;i<SZ(nei2[now]);i++){
		dfs2(nei2[now][i].first);
		dp[now]=max(dp[now],dp[nei2[now][i].first]+nei2[now][i].second);
	}
	dp[now]+=dem[now];
}

INT mxans=0;
INT s;

int main(){
	fio>>n>>m;
	faq[0]=0;
	for(INT i=1;i<100005;i++){
		faq[i]=faq[i-1]+i*(i+1)/2;
	}
	for(INT i=0;i<m;i++){
		INT x,y,z;
		fio>>x>>y>>z;
		hv[i]=z;
		mx[i]=calc(z);
		nei[x].pb(mp(y,i));
	}
	fio>>s;
	for(INT i=1;i<=n;i++){
		if(!lgl[i]){
			tarjan(i);
		}
	}
	INT ans=0;
	for(INT i=1;i<=n;i++){
		for(INT j=0;j<SZ(nei[i]);j++){
			if(blst[i]!=blst[nei[i][j].first]){
				nei2[blst[i]].pb(mp(blst[nei[i][j].first],hv[nei[i][j].second]));
			}else{
				dem[blst[i]]+=mx[nei[i][j].second];
			}
		}
	}
	FILL1(dp);
	dfs2(blst[s]);
	fio<<dp[blst[s]]<<endl;
	return 0;
}