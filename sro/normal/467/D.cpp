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
map<string,INT> dy;
INT cntdy;
string yd[300005];
PII lx[300005];
vector<INT> nei[300005];
INT llk[300005];
INT ini[300005];
INT lgl[300005];
INT tmc[300005],djg,cmt[300005];
vector<INT> stk;
//vector<INT> qlt[300005];
INT cnqlt;
INT blst[300005];

void dfs(INT now){
	stk.pb(now);
	tmc[now]=llk[now]=++djg;
	cmt[djg]=now;
	lgl[now]=1;
	for(INT i=0;i<SZ(nei[now]);i++){
		if(lgl[nei[now][i]]==2){
			continue;
		}
		if(!lgl[nei[now][i]]){
			dfs(nei[now][i]);
		}
		llk[now]=min(llk[now],llk[nei[now][i]]);
	}
	if(tmc[now]==llk[now]){
		cnqlt++;
		while(SZ(stk)){
			INT x=stk.back();
			stk.pob();
			lgl[x]=2;
			blst[x]=cnqlt;
			//qlt[cnqlt].pb(x);
			if(x==now){
				break;
			}
		}
	}
}

PII getlx(const string &s){
	PII x=mp(0,SZ(s));
	for(INT i=0;i<SZ(s);i++){
		if(s[i]=='r'){
			x.first++;
		}
	}
	return x;
}

INT get(const string& s){
	if(!dy.count(s)){
		yd[cntdy]=s;
		dy[s]=cntdy;
		lx[cntdy++]=getlx(s);
	}
	return dy[s];
}

PII minlx[300005];
INT mindjg[300005];
vector<INT> nei2[300005];
set<INT> hv[300005];
PII dp[300005];
bool lgl2[300005];

PII dfs2(INT now){
	if(dp[now]!=mp(INF,INF)){
		return dp[now];
	}
	PII &x=dp[now];
	x=minlx[now];
	//cerr<<minlx[now].second<<' '<<now<<endl;
	lgl2[now]=1;
	for(INT i=0;i<SZ(nei2[now]);i++){
		x=min(x,dfs2(nei2[now][i]));
	}
	return x;
}

int main(){
	fio>>n;
	for(INT i=0;i<n;i++){
		string s;
		fio>>s;
		for(INT j=0;j<SZ(s);j++){
			s[j]=tolower(s[j]);
		}
		ini[i]=get(s);
	}
	fio>>m;
	for(INT i=0;i<m;i++){
		string a,b;
		fio>>a>>b;
		for(INT j=0;j<SZ(a);j++){
			a[j]=tolower(a[j]);
		}
		for(INT j=0;j<SZ(b);j++){
			b[j]=tolower(b[j]);
		}
		nei[get(a)].pb(get(b));
		//cerr<<get(a)<<' '<<get(b)<<endl;
	}
	for(INT i=0;i<cntdy;i++){
		if(!lgl[i]){
			dfs(i);
		}
	}
	for(INT i=1;i<=cnqlt;i++){
		minlx[i]=mp(INF,INF);
	}
	for(INT i=0;i<cntdy;i++){
		if(lx[i]<minlx[blst[i]]){
			minlx[blst[i]]=lx[i];
			mindjg[blst[i]]=i;
		}
	}
	for(INT i=0;i<cntdy;i++){
		for(INT j=0;j<SZ(nei[i]);j++){
			if(blst[i]!=blst[nei[i][j]]&&!hv[blst[i]].count(blst[nei[i][j]])){
				nei2[blst[i]].pb(blst[nei[i][j]]);
				hv[blst[i]].insert(blst[nei[i][j]]);
				//cerr<<llk[i]<<' '<<llk[j]<<endl;
			}
		}
	}
	for(INT i=1;i<=cnqlt;i++){
		dp[i]=mp(INF,INF);
	}
	for(INT i=1;i<=cnqlt;i++){
		if(!lgl2[i]){
			dfs2(i);
		}
	}
	PII ans=mp(0,0);
	for(INT i=0;i<n;i++){
		PII gt=dp[blst[ini[i]]];
		ans.first+=gt.first;
		ans.second+=gt.second;
		//cerr<<dp[blst[ini[i]]].second<<' '<<blst[ini[i]]<<' '<<ini[i]<<endl;
	}
	fio<<ans.first<<' '<<ans.second<<endl;
	return 0;
}