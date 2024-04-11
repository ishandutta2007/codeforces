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
typedef long long Int;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint num[12];
lint dp[12][12][2];
lint dp2[12][12][8];
lint mo=1000000007;
int cal(int a){
	if(a==4 || a==7) return 1;return 0;
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
lint con(int a,int b){
	lint ret=1;int i;
	rep(i,b){
		ret*=(a-i);ret%=mo;ret*=invMod(i+1,mo);ret%=mo;
	}
	return ret;
}
int main()
{
	int i,j,k,l,n;lint out=0;
	cin>>n;vector <int> s;
	while(n>0){s.pb((n%10));n/=10;}
	reverse(All(s));n=s.size();
	
	memset(dp,0,sizeof(dp));dp[0][0][0]=1;
	rep(i,n) rep(j,n+1){
		rep(k,s[i]){
			//if(i<1 && k<1) continue;
			dp[i+1][j+cal(k)][1]+=dp[i][j][0]+dp[i][j][1];
		}
		//if(i>0 || s[i]>0){
			dp[i+1][j+cal(s[i])][0]+=dp[i][j][0];
			dp[i+1][j+cal(s[i])][1]+=dp[i][j][1];
		//}
		REP(k,s[i]+1,10) dp[i+1][j+cal(k)][1]+=dp[i][j][1];
	}
	
	memset(num,0,sizeof(num));
	rep(i,n+1) num[i]+=dp[n][i][0]+dp[n][i][1];num[0]--;
	//rep(i,n+1) cout<<i<<' '<<num[i]<<endl;
	
	memset(dp2,0,sizeof(dp2));dp2[0][0][0]=1;
	rep(i,n) rep(j,n) rep(k,7){
		if(dp2[i][j][k]<1) continue;
		rep(l,7){
			if(j+l*i>=n || k+l>6) continue;
			dp2[i+1][j+i*l][k+l]+=dp2[i][j][k]*con(num[i],l);
			dp2[i+1][j+i*l][k+l]%=mo;
		}
	}
	rep(i,n) REP(j,i+1,12){
		out+=dp2[n][i][6]*num[j];out%=mo;
	}
	cout<<((out*720)%mo)<<endl;
	return 0;
}