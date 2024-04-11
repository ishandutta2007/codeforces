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
typedef complex<double> pt;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint inf=1100000000000LL;
lint zyo[1100000],su[1100000];
int main()
{
	int i,n;lint k,b,t;
	cin>>k>>b>>n>>t;
	zyo[0]=1;su[0]=1;
	rep(i,1050000) zyo[i+1]=min(zyo[i]*k,inf);
	rep(i,1050000) su[i+1]=min(su[i]+zyo[i+1],inf);
	rep(i,n){
		if(t>=zyo[n-i]+b*su[n-i-1]){cout<<i<<endl;return 0;}
	}
	cout<<n<<endl;return 0;
}