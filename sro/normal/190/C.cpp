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
using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int Uint;
typedef long long INT;
typedef pair<INT,INT> PII;
typedef vector<int> vint;
typedef vector<INT> VINT;
typedef vector<pii> vpii;
typedef vector<PII> VPII;
typedef greater<int> gint;
typedef greater<INT> GINT;
typedef greater<pii> gpii;
typedef greater<PII> GPII;

queue<string> stk;
stack<int> pro;
int needtype=1;
string s;

int main()
{
	getline(cin,s);
	while(cin>>s)
	{
		stk.push(s);
		needtype--;
		if(needtype==-1)OVER("Error occurred");
		if(s=="pair")needtype+=2;
	}
	if(needtype)OVER("Error occurred");
	if(SZ(stk)==1&&stk.front()=="int")OVER("int");
	while(stk.size())
	{
		cout<<stk.front();
		if(stk.front()=="pair")
		{
			pro.push(2);
		}
		stk.pop();
		while(pro.size())
		{
			if(pro.top()==2){cout<<"<";break;}
			else if(pro.top()==1){cout<<",";break;}
			else{cout<<">",pro.pop();}
		}
		if(pro.size())
		{
			int to=pro.top();
			pro.pop();
			pro.push(to-1);
		}
	}
	return 0;
}