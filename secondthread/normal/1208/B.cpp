
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin>>n;
	vector<int> a(n);
	for (int i=0; i<n; i++) cin>>a[i];
	int best=n;
	for (int lEx=0; lEx<n; lEx++) {
		set<int> seen;
		bool possible=true;
		for (int i=0; i<lEx; i++) {
			if (seen.find(a[i])!=seen.end()) possible=false;
			seen.insert(a[i]);
		}
		if (!possible) continue;
		best=min(best, n-lEx);
		for (int i=n-1; i>=lEx; i--) {
			if (seen.find(a[i])==seen.end()) {
				//cout<<"Valid "<<lEx<<" "<<i<<endl;
				best=min(best, i-lEx);
				seen.insert(a[i]);
			}
			else {
				break;
			}
		}
	}
	cout<<best<<'\n';

	return 0;
}