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
lint a[1100000];
int co[110000];
lint gcd( lint m, lint n )
{
	lint a=max(m,n),b=min(m,n);
	if(m==0) return n;if(n==0) return m;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}
int main()
{
	int n;lint out=0;cin>>n;
	rep(i,n) scanf("%I64d",&a[i]);
	rep(it,11){
		lint x=a[((rand()<<15)|rand())%n];//cout<<x<<endl;
		vector <lint> ya;
		for(lint i=1;i*i<=x;i++){
			if(x%i==0){
				ya.pb(i);
				if(i*i<x) ya.pb(x/i);
			}
		}
		sort(All(ya));
		int m=ya.size();
		memset(co,0,sizeof(co));
		rep(i,n){
			lint g=gcd(x,a[i]);
			co[(lower_bound(All(ya),g)-ya.begin())]++;
		}
		rep(i,m){
			REP(j,i+1,m){
				if(ya[j]%ya[i]==0) co[i]+=co[j];
			}
			if(co[i]*2>=n && out<ya[i]) out=ya[i];
		}
	}
	cout<<out<<endl;
}