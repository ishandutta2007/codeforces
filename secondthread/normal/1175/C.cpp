#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T; cin>>T;
	for (int tt=1; tt<=T; tt++) {
		vector<int> a;
		int n, k; cin>>n>>k;
		for (int i=0; i<n; i++) {
			int temp; cin>>temp;
			a.push_back(temp);
		}
		int ans=1<<30;
		int val=-1;
		for (int i=0; i+k<n; i++) {
			int candAns=(a[i+k]-a[i]+1)/2;
			if (candAns<ans) {
				ans=candAns;
				val=(a[i+k]+a[i])/2;
			}
		}
		cout<<val<<'\n';

	}
	return 0;
}