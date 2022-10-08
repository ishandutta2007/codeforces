#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int maxn=201;
const int maxk=201;
ll dp[maxn][maxk];

int n, k;
vector<int> a;

ll oo=1e16;

ll go(int lastPicked, int toPickLeft) {
	if (toPickLeft==0)  {
		if (n-1-lastPicked>=k) return -oo;
		else return 0;
	}
	if (lastPicked==n-1) return 0;
	if (lastPicked!=-1 && dp[lastPicked][toPickLeft]!=-1)
		return dp[lastPicked][toPickLeft];

	ll best=-oo;
	for (int nextPick=lastPicked+1; nextPick<min(lastPicked+k+1, n); nextPick++)
		best=max(best, a[nextPick]+go(nextPick, toPickLeft-1));

	if (lastPicked!=-1)
		dp[lastPicked][toPickLeft]=best;
	return best;
}

int main() {
	for (int i=0; i<maxn; i++)
		for (int j=0; j<maxk; j++)
			dp[i][j]=-1;
	int x; cin>>n>>k>>x;
	a.resize(n);
	for (int i=0; i<n; i++) cin>>a[i];

	ll ans=go(-1, x);
	if (ans<0) cout<<-1<<'\n';
	else cout<<ans<<'\n';
	return 0;
}