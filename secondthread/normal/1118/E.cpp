#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k;
	cin>>n>>k;
	if (n>k*k-k) {
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	int first=0, delta=1;
	for (int i=0; i<n; i++) {
		int a=first, b=(first+delta)%k;
		cout<<a+1<<" "<<b+1<<'\n';
		first++;
		if (first==k) {
			first=0;
			delta++;
		}
	}
	return 0;
}