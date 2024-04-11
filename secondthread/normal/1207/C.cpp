
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200002;
ll dp[2][maxn];
ll n, pipeCost, pillarCost;
vector<int> forcedHigh;
ll oo=1e17;

ll go(bool high, int x) {
	if (x==n) {
		return 0; 
	}
	if (dp[high][x]!=-1) return dp[high][x];
	ll best=oo;
	if (forcedHigh[x]) {
		if (!high) return oo;
		best=go(1, x+1)+pillarCost;
	}
	else {
		//stay high
		best=go(1, x+1)+(high?pillarCost:0)+(high?0:2*pipeCost);
		//go low
		best=min(best, go(0, x+1)+(high?pillarCost:0));
	}

	//cout<<"DP high: "<<high<<" x: "<<x<<" is "<<best<<'\n';
	return dp[high][x]=best;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T; cin>>T;
	while (T--) {
		for (int i=0; i<2; i++)
			for (int j=0; j<maxn; j++)
				dp[i][j]=-1;
		cin>>n>>pipeCost>>pillarCost;  
		forcedHigh.clear();
		forcedHigh.resize(n);
		string line; cin>>line;
		for (int i=0; i<n; i++) forcedHigh[i]=(line[i]!='0');
		ll ans=go(0, 0);
		ans+=pillarCost*(n+1)+pipeCost*n;
		cout<<ans<<'\n';
	}
	return 0;
}