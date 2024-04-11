#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int n; cin>>n;
	vector<int> a;
	for (int i=0; i<n; i++) {
		int t; cin>>t;
		a.push_back(t);
	}
	int k=1e9+1;
	for (int m=0; m<n; m++) {
		if (m!=0) k=min(k, a[m]/m);
		if (m!=n-1) k=min(k, a[m]/(n-m-1));
	}
	cout<<k<<endl;
	return 0;
}