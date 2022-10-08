
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

bool isPrime(int n) {
	if (n==1) return false;
	if (n<4) return true;
	for (int i=2; i*i<=n; i++) {
		if (n%i==0) return false;
	}
	return true;
}

int main() {
	int n; cin>>n;
	int nEdges=0;
	vector<ii> ans;
	for (int i=0; i<n; i++) {
		ans.push_back({i, (i+1)%n});
	}
	int index=0;
	while (!isPrime(ans.size())) {
		ans.push_back({index, (index+2)%n});
		if (!isPrime(ans.size())) {
			ans.push_back({(index+1)%n, (index+3)%n});
		}
		index+=4;
	}
	cout<<ans.size()<<'\n';
	for (int i=0; i<ans.size(); i++) {
		cout<<ans[i].first+1<<" "<<ans[i].second+1<<"\n";
	}
	return 0;
}