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
lint gcd( lint m, lint n )
{
	lint a=max(m,n),b=min(m,n);
	if(m==0) return n;if(n==0) return m;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
lint lcm(lint a,lint b){
	return a/gcd(a,b)*b;
}
int main()
{
	int n;
	cin>>n;lint now=2;
	REP(i,1,n+1){
		lint lc=lcm(i,i+1);
		lint t=(lint)sqrt(0.1+(now-1)/lc/lc);
		//cout<<now<<' '<<lc<<' '<<t<<endl;
		printf("%I64d\n",(lc/i*lc*(t+1)*(t+1)-now/i));now=(1+t)*lc;
	}
}