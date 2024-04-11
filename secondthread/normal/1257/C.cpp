#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T; cin>>T;
	while (T--) {
		int n; cin>>n;
		vector<int> a(n);
		for (int i=0; i<n; i++) cin>>a[i];
		
		vector<int> indexOf(n+1, n+1);
		int ans=n+1;
		for (int i=n-1; i>=0; i--) {
			if (indexOf[a[i]]!=n+1) {
				ans=min(ans, indexOf[a[i]]-i);
			}
			indexOf[a[i]]=i;
		}

		if (ans==n+1) {
			cout<<-1<<'\n';
		}
		else {
			cout<<ans+1<<'\n';
		}

	}
	return 0;
}