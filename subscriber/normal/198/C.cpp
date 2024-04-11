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
double pi=acos(-1);

long double xp,yp,vp,x,y,v,r,R,u,ll,rr,cc,uu,X,Y,a,b,c,d,h,T,TT,U,ans=1e18,A,B,D,FU,aa,bb,AA,BB,DD;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> xp >> yp >> vp;
	cin >> x >> y >> v >> r;
	R=sqrt(xp*xp+yp*yp);
	u=pi/2-atan2(xp,yp);
	ll=0;
	rr=1e9;
	for (int it=0;it<5000;it++){
		cc=(ll+rr)/2;
		uu=u+cc;
		TT=cc*R/vp;
		X=cos(uu)*R;
		Y=sin(uu)*R;
		a=Y-y;
		b=x-X;
		c=-x*a-y*b;
		d=fabs(c)/sqrt(a*a+b*b);
		if (d>r)T=sqrt(sqr(x-X)+sqr(y-Y))/v;else{
			aa=-b;
			bb=a;
			if ((aa*x+bb*y)*(aa*X+bb*Y)>0){
				T=sqrt(sqr(x-X)+sqr(y-Y))/v;				
			}else{
				AA=x*x+y*y;
				BB=xp*xp+yp*yp;
				DD=sqr(x-X)+sqr(y-Y);
				A=sqrt(x*x+y*y);
				B=sqrt(xp*xp+yp*yp);
				D=sqrt(sqr(x-X)+sqr(y-Y));
				FU=acos(-(DD-AA-BB)/2/A/B);
				T=sqrt(AA-r*r)/v;
				T+=sqrt(BB-r*r)/v;
				FU-=acos(r/A);
				FU-=acos(r/B);
				T+=r*FU/v;
			}
		}
		if (T<TT+1e-17)ans=min(ans,TT),rr=cc;else ll=cc;
	}
	cout.precision(20);
	CC(ans);
	return 0;
}