#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int> > iii;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	vector<iii> inc, dec;
	for (int i=1; i<=n; i++) {
		int a, b; cin>>a>>b;
		if (a<b)
			inc.push_back({a, {b, i} });
		else
			dec.push_back({a, {b, i} });
	}
	sort(inc.begin(), inc.end(), [] (const auto &lhs, const auto &rhs) {
			return lhs.second.first<rhs.second.first;	
			});
	sort(dec.begin(), dec.end(), [] (const auto &lhs, const auto &rhs) {
			return lhs.second.first<rhs.second.first;	
			});
	if (inc.size()>dec.size()) {
		cout<<inc.size()<<'\n';	
		for (int i=0; i<inc.size(); i++) {
			cout<<inc[inc.size()-1-i].second.second<<" \n"[i==inc.size()-1];
		}
	}
	else {
		cout<<dec.size()<<'\n';
		for (int i=0; i<dec.size(); i++) {
			cout<<dec[i].second.second<<" \n"[i==dec.size()-1];
		}
	}

	return 0;
}