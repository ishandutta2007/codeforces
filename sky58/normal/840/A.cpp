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
#include<cassert>
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
int a[252521],b[252521],b2[252521],out[252521];
vector<pint> v;
int main()
{
	int n;
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n){
		scanf("%d",&b[i]);
		v.pb(mp(b[i],i));
	}
	sort(All(v));
	rep(i,n) b2[v[i].se]=i;
	sort(a,a+n);reverse(a,a+n);
	rep(i,n) out[v[i].se]=a[i];
	rep(i,n){
		printf("%d",out[i]);
		if(i<n-1) printf(" ");
		else printf("\n");
	}
}