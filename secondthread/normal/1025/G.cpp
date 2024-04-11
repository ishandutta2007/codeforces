#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1000000007;

static ll fastPow(ll base, ll exp) {
	if (exp==0) return 1;
	ll half=fastPow(base, exp/2);
	if (exp%2==0) return half*half%mod;
	return half*half%mod*base%mod;
}

int main() {
	int n; cin>>n;
	ll start=0, end=fastPow(2, n-1)-1;
	vector<int> nKids(n, 0);
	for (int i=0; i<n; i++) {
		int par; cin>>par;
		if (par==-1) continue;
		nKids[par-1]++;
	}
	for (int i:nKids) {
		start+=fastPow(2, i)-1;
	}
	//cout<<start<<" "<<end<<endl;
	ll diff=((end-start)%mod+mod)%mod;
	cout<<diff<<endl;
	return 0;
}