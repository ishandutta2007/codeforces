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
typedef unsigned long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int ne[252],lo[252],to[252];
lint gcd( lint m, lint n )
{
	lint a=max(m,n),b=min(m,n);
	if(m==0) return n;if(n==0) return m;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
lint lcm( lint m, lint n )
{
	if (( 0 == m ) || ( 0 == n )) return 0;
	return ((m / gcd(m, n)) * n);
}
int main()
{
	int n;cin>>n;
	memset(lo,-1,sizeof(lo));
	memset(to,0,sizeof(to));
	rep(i,n){
		cin>>ne[i];ne[i]--;
	}
	rep(i,n){
		int now=i;
		rep(j,214){
			now=ne[now];
			if(now==i){
				lo[i]=j+1;break;
			}
		}
	}
	rep(i,n){
		if(lo[i]>=0) continue;
		int now=i;
		rep(j,214){
			now=ne[now];
			if(lo[now]>=0){
				to[i]=j+1;break;
			}
		}
	}
	lint lc=1,ma=0,out;
	rep(i,n){
		if(lo[i]>0) lc=lcm(lc,lo[i]);
		ma=max(ma,(lint)to[i]);
	}
	out=lc;while(out<ma) out+=lc;
	cout<<out<<endl;
}