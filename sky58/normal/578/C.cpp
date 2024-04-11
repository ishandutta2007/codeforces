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
int a[252521];
double b[252521];
int main()
{
	int n;
	double lo=-1e15,hi=1e15,out=1e15;
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,100){
		double mi=0.5*(lo+hi),l2=0,h2=0;
		/*rep(j,n-1){
			l2=max(l2,0.5*(a[j]+a[j+1]-mi));
			h2=min(h2,0.5*(a[j]+a[j+1]+mi));
		}*/
		rep(j,n) b[j]=a[j]-mi;
		double sl=0.0,sh=0.0;
		rep(j,n){
			sl=min(0.0,sl+b[j]);
			sh=max(0.0,sh+b[j]);
			l2=min(l2,sl);h2=max(h2,sh);
		}
		if(h2<=1e-9) hi=mi;
		else if(l2>=-1e-9) lo=mi;
		else if(h2>-l2) lo=mi;
		else hi=mi;
		out=min(out,max(h2,-l2));
		//cout<<mi<<' '<<l2<<' '<<h2<<endl;
	}
	printf("%.12f\n",out);
}