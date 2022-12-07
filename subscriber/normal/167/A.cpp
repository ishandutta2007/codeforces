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

int n;
pair<pt,int>q[111111];
double a,d,l,r,c,s=0,ans[111111],t;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> a >> d;
	for (int i=0;i<n;i++)cin >> q[i].F.F >> q[i].F.S;
	for (int i=0;i<n;i++)q[i].S=i;
	sort(q,q+n);
	for (int i=0;i<n;i++){
		l=0;
		r=1e12;
		for (int j=0;j<300;j++){
			c=(l+r)/2;
			if (q[i].F.S/a>c)t=c*a*c/2;else
			t=(q[i].F.S/a)*q[i].F.S/2+(c-q[i].F.S/a)*q[i].F.S;
			if (t>d)r=c;else l=c;
		}
		s=max(s,l+q[i].F.F);
		ans[q[i].S]=s;
	}
	cout.precision(20);
	for (int i=0;i<n;i++)CC(ans[i]);
	return 0;
}