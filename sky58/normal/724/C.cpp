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
lint inf=1145141919810364364LL;
lint X[114514],Y[114514],out[114514];
lint extgcd(lint a, lint b, lint &x, lint &y) {
  lint g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}
lint invMod(lint a, lint m) {
  lint x, y;
  if (extgcd(a, m, x, y) == 1) return (x + m) % m;return 0;
}
lint gcd( lint m, lint n )
{
	lint a=max(m,n),b=min(m,n);
	if(m==0LL) return n;if(n==0LL) return m;
	if(a%b==0LL) return b;
	return gcd(b,a-b*(a/b));
}
lint lcm(lint n,lint m){
	return n/gcd(n,m)*m;
}
lint ca2(lint n,lint m,lint x,lint y){
	//cout<<n<<' '<<m<<' '<<x<<' '<<y<<endl;
	lint z=y-x,ret=0,w=(z%m+m)%m,gc=gcd(n,m);
	if(w%gc>0) return inf;
	lint N=n/gc,M=m/gc,W=w/gc;
	lint a=(W*invMod(N,M))%M,b=(a*N-z/gc)/M;
	lint lc=lcm(N,M);
	if(b<0){
		lint c=lc/M,d=(c-1-b)/c;
		a+=lc/N*d;b+=lc/M*d;
	}
	//cout<<a<<' '<<b<<' '<<a*n+x<<endl;
	if(a*n+x!=b*m+y){
		while(1){}
	}
	return a*n+x;
}
lint cal(lint n,lint m,lint x,lint y){
	//cout<<n<<' '<<m<<' '<<x<<' '<<y<<endl;
	lint ret=inf;
	ret=min(ret,ca2(2*n,2*m,x,y));
	ret=min(ret,ca2(2*n,2*m,2*n-x,y));
	ret=min(ret,ca2(2*n,2*m,x,2*m-y));
	ret=min(ret,ca2(2*n,2*m,2*n-x,2*m-y));
	return ret;
}
int main()
{
	lint n,m;int k,N,M;
	scanf("%d %d %d",&N,&M,&k);n=N;m=M;
	//cout<<n<<' '<<m<<' '<<k<<endl;
	rep(i,k){
		scanf("%d %d",&N,&M);X[i]=N;Y[i]=M;
	}
	rep(i,k){
		out[i]=cal(n,m,X[i],Y[i]);
	}
	rep(i,k){
		if(out[i]>=inf) printf("-1\n");
		else printf("%I64d\n",out[i]);
	}
}