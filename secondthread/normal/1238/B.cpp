#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int T; cin>>T;
	for (int tt=0; tt<T; tt++) {
		int n, r; cin>>n>>r;
		vector<int> a(n);
		for (int i=0; i<n; i++) cin>>a[i];
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
		ll min=0;
		int count=0;
		for (int i=a.size()-1; i>=0; i--) {
			if (a[i]<=min) continue;
			min+=r;
			count++;
		}
		cout<<count<<endl;
	}
}