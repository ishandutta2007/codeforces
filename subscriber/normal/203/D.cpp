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
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

double a,b,m,vx,vy,vz,t,x,y;

double oo(double x,double a){
	if (x>0){
		int d=x/a/2;
		x-=d*a*2;
		if (x>a)x=a-(x-a);
	}else{
		int d=x/a/2;
		x-=d*a*2;
		if (x<-a)x=a-(-x-a);
		if (x<0)x=-x;
	}
	return x;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> a >> b >> m >> vx >> vy >> vz;
	t=-m/vy;
	x=a/2+vx*t;
	y=vz*t;
	x=oo(x,a);
	y=oo(y,b);
	printf("%.9lf %.9lf\n",x,y);
	return 0;
}