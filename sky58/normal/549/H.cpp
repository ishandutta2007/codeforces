#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
double calhi(double x,double y,double z){
	double a=x+z,b=x-z,c=y+z,d=y-z;
	return max(max(a*c,a*d),max(b*c,b*d));
}
double callo(double x,double y,double z){
	double a=x+z,b=x-z,c=y+z,d=y-z;
	return min(min(a*c,a*d),min(b*c,b*d));
}
int main()
{
	double a,b,c,d,lo=0,hi=1e9;
	cin>>a>>b;cin>>c>>d;
	rep(i,100){
		double mi=0.5*(lo+hi);
		double l0=callo(a,d,mi),l1=callo(b,c,mi);
		double h0=calhi(a,d,mi),h1=calhi(b,c,mi);
		if(l0<=h1 && l1<=h0) hi=mi;else lo=mi;
		//cout<<mi<<' '<<l0<<' '<<h0<<' '<<l1<<' '<<h1<<endl;
	}
	printf("%.12f\n",lo);
}