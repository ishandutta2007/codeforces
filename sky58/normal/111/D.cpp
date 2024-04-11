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
using namespace std;
#define pb push_back
typedef long long lint;
typedef long long Int;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint dp[1100][1100];
lint mo=1000000007;
vector <lint> kai;
lint zyo(lint x,lint y){
    lint ret=1,a=x;
    while(y>0){
    	if(y%2==1) ret=(ret*a)%mo;
    	a=(a*a)%mo;y/=2;
    }
    return ret;
}
Int extgcd(Int a, Int b, Int &x, Int &y) {
  Int g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}
Int invMod(Int a, Int m) {
  Int x, y;
  if (extgcd(a, m, x, y) == 1) return (x + m) % m;return 0;
}
int main()
{
	lint i,j,out=0;int n,m,k,x,y;
	cin>>n>>m>>k;
	if(m<2){cout<<zyo(k,n)<<endl;return 0;}
	kai.pb(1);rep(i,1000010) kai.pb((kai[i]*(i+1))%mo);
	rep(i,1100) rep(j,1100) dp[i][j]=0;dp[0][0]=1;
	rep(i,1050) rep(j,i+1){
		dp[i+1][j]=(dp[i+1][j]+dp[i][j]*j)%mo;
		dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*(j+1))%mo;
	}
	REP(x,1,n+1) REP(y,max(2*x-k,0),x+1){
		lint t=(kai[k]*invMod(kai[y],mo))%mo;
		t*=invMod(kai[x-y],mo);t%=mo;
		t*=invMod(kai[x-y],mo);t%=mo;
		t*=invMod(kai[k-2*x+y],mo);t%=mo;
		t*=zyo(y,n*(m-2));t%=mo;
		t*=dp[n][x];t%=mo;
		out=(out+t*dp[n][x])%mo;
	}
	cout<<out<<endl;
	return 0;
}