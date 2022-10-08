#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	--n;
	ll number;
	cin>>number;
	vector<ll> candidates;
	ll left=number;
	for (ll i=2; i*i<=number; i++) {
		while (left%i==0) {
			left/=i;
			candidates.push_back(i);
		}
	}
	if (left!=1) candidates.push_back(left);
	for (int tt=0; tt<n; tt++) {
		cin>>number;
		vector<ll> newCands;
		for (ll c:candidates)
			if (number%c==0) {
				newCands.push_back(c);
				number/=c;
			}
		candidates=newCands;
	}
	set<ll> ans;
	ans.insert(1);
	for (ll c:candidates) {
		set<ll> newAns;
		for (ll old:ans) {
			newAns.insert(old);
			newAns.insert(old*c);
		}
		ans=newAns;
	}
	cout<<ans.size()<<'\n';

	return 0;
}