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
set<int> s;
int a[364364],out[364364];
vector<pint> v;
int main()
{
	int n,k;lint sum=0;
	scanf("%d %d",&n,&k);
	rep(i,n){
		scanf("%d",&a[i]);
		v.pb(mp(a[i],i));
		s.insert(k+i);
	}
	sort(All(v));reverse(All(v));
	rep(i,n){
		int p=v[i].se;
		set<int>::iterator it=s.lower_bound(p);
		int x=(*it);
		out[p]=x;sum+=(lint)a[p]*(x-p);
		s.erase(it);
	}
	cout<<sum<<endl;
	rep(i,n){
		printf("%d",out[i]+1);
		if(i<n-1) printf(" ");else printf("\n");
	}
}