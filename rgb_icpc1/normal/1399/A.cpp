#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin>>n;
	vector<int> a(n);
	for (int &p:a) cin>>p;
	sort(a.begin(), a.end());
	for (int i = 1; i < n; i ++) {
		if (a[i] > 1 + a[i-1]) {
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
}

int main() {
	int T;
	cin>>T;
	while (T --) solve();	
}