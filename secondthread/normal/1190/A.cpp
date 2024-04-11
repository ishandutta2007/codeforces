#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll n, nSpecial, k; cin>>n>>nSpecial>>k;
	vector<ll> special;
	for (int i=0; i<nSpecial; i++) {
		ll temp; cin>>temp;
		special.push_back(temp-1);
	}
	int specialIndex=0;
	ll removed=0;
	int turns=0;
	while (specialIndex<special.size()) {
		ll val=special[specialIndex]-removed;
		ll page=val/k;
		ll curPage=val/k;
		ll toAdd=0;
		while (specialIndex<special.size()&&curPage==page) {
			toAdd++;
			specialIndex++;
			if (specialIndex<special.size()) {
				curPage=(special[specialIndex]-removed)/k;
			}
		}
		removed+=toAdd;
		turns++;
	}
	cout<<turns<<endl;

	return 0;
}