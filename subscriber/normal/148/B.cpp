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
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

int p,d,t,f,c,ans=0;
double l,r,cc,e;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> p >> d >> t >> f >> c;
	e=p*t;
	while (e+1e-9<c){
		l=0;
		r=1e9;
		while (r-l>1e-14){
			cc=(l+r)/2;
			if (d*cc>e+p*cc)r=cc;else l=cc;
		}
		if (e+l*p+1e-9>c)break;
		ans++;
		e+=(l+l+f)*p;
	}
	CC(ans);
	return 0;
}