#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin>>n;
	vector<ll> a(n, 0);
	for (int i=0; i<n; i++) cin>>a[i];
	vector<vector<ll>> multiplesOf(64, vector<ll>());
	for (ll i:a) {
		int times=0;
		while ((i&(1ll<<times))==0) {
			times++;
		}
		multiplesOf[times].push_back(i);
	}
	int maxIndex=0;
	for (int i=0; i<multiplesOf.size(); i++) {
		if (multiplesOf[i].size()>multiplesOf[maxIndex].size())
			maxIndex=i;
	}
	cout<<n-multiplesOf[maxIndex].size()<<endl;
	for (int i=0; i<multiplesOf.size(); i++) {
		if (i==maxIndex) continue;
		for (ll j:multiplesOf[i]) {
			cout<<j<<" ";
		}
	}
	cout<<endl;
	return 0;
}