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
int ret[310000];
int main()
{
	int n,a;vector<pint> p;
	scanf("%d",&n);
	rep(i,n){
		scanf("%d",&a);p.pb(mp(a,i));
	}
	sort(All(p));
	rep(i,n){
		if(i>0) p[i].fi=max(p[i].fi,p[i-1].fi+1);
		ret[p[i].se]=p[i].fi;
	}
	rep(i,n){
		if(i<n-1) printf("%d ",ret[i]);
		else printf("%d\n",ret[i]);
	}
}