
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T; cin>>T;
	while (T--) {
		int n; cin>>n;
		vector<int> a(n, 0);
		for (int i=0; i<n; i++) cin>>a[i];
		bool works=false;
		for (int start=0; start<n; start++) {
			bool posWorks=true, negWorks=true;
			for (int d=0; d<n; d++) {
				if (a[(start+d)%n]!=d+1)posWorks=false;
				if (a[((start-d)%n+n)%n]!=d+1)negWorks=false;
			}
			works|=(posWorks||negWorks);
		}
		cout<<(works?"YES":"NO")<<'\n';
	}
	return 0;
}