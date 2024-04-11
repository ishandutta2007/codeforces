/*

short-32768~32767
unsigned short0~65535
int-2147483648~2147483647
uint0~4294967295
INT-9223372036854775808~9223372036854775807
UINT0~18446744073709551615
float-3.4e38~3.4e386~7
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
#define win(c,a) (a[0]==c&&a[1]==c&&a[2]==c||a[3]==c&&a[4]==c&&a[5]==c||a[6]==c&&a[7]==c&&a[8]==c||a[0]==c&&a[3]==c&&a[6]==c||a[1]==c&&a[4]==c&&a[7]==c||a[2]==c&&a[5]==c&&a[8]==c||a[0]==c&&a[4]==c&&a[8]==c||a[2]==c&&a[4]==c&&a[6]==c)
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

map<string,string> mss;
char ch[9],in[9];
int cnx,cno;
char zt[3]={'.','X','0'};

string what()
{
	bool winx=win('X',ch),wino=win('0',ch);
	if(winx&&!wino&&cnx==cno+1)return "the first player won";
	if(wino&&!winx&&cnx==cno)return "the second player won";
	int draw=1;
	for(int i=0;i<9;i++)if(ch[i]=='.')draw=0;
	if(!winx&&!wino&&draw&&cnx==cno+1)return "draw";
	if(!winx&&!wino&&cnx==cno)return "first";
	if(!winx&&!wino&&cnx==cno+1)return "second";
	return "illegal";
}

void solve(int djg)
{
	if(djg==9)
	{
		string str=what();
		if(str!="illegal")mss[ch]=str;
		return;
	}
	for(int i=0;i<3;i++)
	{
		ch[djg]=zt[i];
		if(zt[i]=='0')cno++;
		if(zt[i]=='X')cnx++;
		solve(djg+1);
		if(zt[i]=='0')cno--;
		if(zt[i]=='X')cnx--;
		ch[djg]=0;
	}
}

int main()
{
	solve(0);
	scanf("%s\n%s\n%s",in,in+3,in+6);
	if(!mss.count(in))OVER("illegal");
	cout<<mss[in]<<endl;
	return 0;
}