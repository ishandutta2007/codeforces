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
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
typedef long long Int;
lint con[1100][1100];
lint dp[110][1100];
lint mo=1000000007;
int x[110],y[110],sa[110];
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
	int m,n=0,i,j,k;
	memset(sa,0,sizeof(sa));
	for(i=0;i<1100;i++) for(j=0;j<1100;j++) con[i][j]=0;
	for(i=0;i<110;i++) for(j=0;j<1100;j++) dp[i][j]=0;
	con[0][0]=1;dp[0][0]=1;
	for(i=1;i<1050;i++) for(j=0;j<=i;j++){
		con[i][j]+=con[i-1][j];if(j>0) con[i][j]+=con[i-1][j-1];con[i][j]%=mo;
	}
	cin>>m;
	for(i=0;i<m;i++){cin>>x[i];n+=x[i];sa[i+1]=n;}
	for(i=0;i<m;i++) cin>>y[i];
//	for(i=0;i<m+1;i++) cout<<sa[i]<<endl;
	for(i=0;i<m;i++) for(j=0;j<=sa[i];j++){
		if(dp[i][j]<=0) continue;
//		cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
		for(k=0;k<=y[i] && k+j<=sa[i+1];k++){
			dp[i+1][j+k]=(dp[i+1][j+k]+dp[i][j]*con[sa[i+1]-j][k])%mo;
		}
	}
	for(i=1;i<=n;i++) dp[m][n]=(dp[m][n]*i)%mo;
	for(i=0;i<m;i++) for(j=1;j<=x[i];j++) dp[m][n]=(dp[m][n]*invMod(j,mo))%mo;
	cout<<(dp[m][n]%mo)<<endl;
	return 0;
}