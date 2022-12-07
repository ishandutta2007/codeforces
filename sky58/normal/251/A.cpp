#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
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
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int main()
{
	int n,d,i,b;lint out=0;
	vector <int> a;
	cin>>n>>d;
	rep(i,n){
		scanf("%d",&b);a.pb(b);
	}
	sort(All(a));
	rep(i,n){
		b=upper_bound(All(a),a[i]+d)-a.begin();
		b-=i;
		//cout<<b<<endl;
		if(b>2) out+=(lint)(b-1)*(b-2)/2;
	}
	cout<<out<<endl;
	return 0;
}