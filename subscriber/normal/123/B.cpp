#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define SV(x) sort(x.begin(),x.end())
#define pw(x) (1ull<<(x))
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;
typedef unsigned long long UL;

long long a,b,x,y,xx,yy,ax,ay,bx,by,aa,bb;


int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> a >> b >> x >> y >> xx >> yy;
	aa=(a+a)*2000000000;
	bb=(b+b)*2000000000;
	ax=(x+y+aa)/(a+a);
	ay=(x-y+bb)/(b+b);
	bx=(xx+yy+aa)/(a+a);
	by=(xx-yy+bb)/(b+b);
	CC(max(abs(ax-bx),abs(ay-by)));
	return 0;
}