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
typedef pair<pint,pint> fint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int gcd( lint m, lint n )
{
	lint a=max(m,n),b=min(m,n);
	if(m==0) return n;if(n==0) return m;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
lint cal(lint lo,lint hi,lint mi){
	if(mi<=lo) return lo;
	if(mi>=hi) return hi;
	if(lo%2==mi%2) return mi;
	return mi-1;
}
int main()
{
	lint n,m,x,y,a,b;
	cin>>n>>m>>x>>y>>a>>b;
	lint c=gcd(a,b);a/=c;b/=c;
	lint d=min(n/a,m/b);a*=d;b*=d;
	n*=2;m*=2;x*=2;y*=2;
	n-=a;m-=b;
	lint rx=cal(a,n,x),ry=cal(b,m,y);
	cout<<(rx-a)/2<<' '<<(ry-b)/2<<' '<<(rx+a)/2<<' '<<(ry+b)/2<<endl;
	return 0;
}