#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

const int N=300300;
int n;
nagai a[N];
nagai pref[N];
nagai dp[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i)pref[i+1]=pref[i]+a[i];
	dp[0]=0;
	for(int i=1;i<=n;++i){
		dp[i]=dp[i-1];
		nagai kek=min(a[i-1]/2,pref[i-1]-dp[i-1]*3);
		dp[i]+=kek;
		dp[i]+=(a[i-1]-2*kek)/3;
	}
	cout<<dp[n]<<'\n';
	return 0;
}