#include <iostream>
#include <map>
#define int long long
#define mod 1000000007
using namespace std;
int a[200005],lst[200005],dp[200005];
map <int,int> mp,S;
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--)
	{
		mp.clear();
		S.clear();
		int now=0;
		int n;
		cin >> n;
		cin >> now;
		dp[1]=1;
		int s=1;
		S[0]=1;
		for(int i=2;i<=n;i++)
		{
			int x;
			cin >> x;
			now+=x;
			dp[i]=(s+dp[i-1]-S[now-x])%mod;
			dp[i]=(dp[i]+mod)%mod;
			S[now-x]=(S[now-x]+dp[i]-dp[i-1])%mod;
			s=(s+dp[i]-dp[i-1]+mod)%mod;
		}
		cout << dp[n] << "\n";
	}
	return 0;
}