#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin>>n>>k;
	string rep;
	for (int i=0; i<(n-k)/2; i++) rep.push_back('0');
	rep.push_back('1');
	for (int i=0; i<n; i++)
		cout<<rep[i%rep.length()];
	cout<<endl;

	return 0;
}