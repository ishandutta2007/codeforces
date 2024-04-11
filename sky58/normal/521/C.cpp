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
lint zyo[114514],sum[114514],kai[114514];
lint mo=1000000007;
lint extgcd(lint a, lint b, lint &x, lint &y) {
  lint g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}
lint invMod(lint a, lint m) {
  lint x, y;
  if (extgcd(a, m, x, y) == 1) return (x + m) % m;return 0;
}
lint co(int a,int b){
	if(a<0 || b<0 || b>a) return 0;
	return ((kai[a]*invMod(kai[b],mo))%mo*invMod(kai[a-b],mo))%mo;
}
int main()
{
	lint out=0;int n,k;string s;
	zyo[0]=kai[0]=1;sum[0]=0;
	rep(i,100100){
		zyo[i+1]=(zyo[i]*10)%mo;
		kai[i+1]=(kai[i]*(i+1))%mo;
		//sum[i+1]=(sum[i]+zyo[i])%mo;
	}
	cin>>n>>k;cin>>s;
	reverse(All(s));
	rep(i,n) sum[i+1]=sum[i]+(s[i]-'0');
	rep(i,n){
		int now=(s[i]-'0');
		out=(out+(zyo[i]*co(n-i-1,k))%mo*now)%mo;
		//out=(out+(sum[i]*co(n-i-2,k-1))%mo*now)%mo;
		//cout<<out<<endl;
	}
	REP(i,1,n){
		lint now=sum[n]-sum[i];
		out=(out+(zyo[i-1]*co(n-i-1,k-1))%mo*now)%mo;
	}
	cout<<out<<endl;
}