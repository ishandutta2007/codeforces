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

char x,xx;
int y,yy;
vector<string> a;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	scanf("%c%d\n%c%d",&x,&y,&xx,&yy);
	while (x<xx){
		if (y<yy)y++,a.pb("RU");else
		if (y>yy)y--,a.pb("RD");else a.pb("R");
		x++;
	}
	while (x>xx){
		if (y<yy)y++,a.pb("LU");else
		if (y>yy)y--,a.pb("LD");else a.pb("L");
		x--;
	}
	while (y<yy)y++,a.pb("U");
	while (y>yy)y--,a.pb("D");
	CC(a.size());
	for (int i=0;i<a.size();i++)CC(a[i]);
	return 0;
}