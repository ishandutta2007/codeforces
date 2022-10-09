#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T; cin>>T;
	while (T--) {
		int from, to; cin>>from>>to;
		bool works=false;
		if (from==1) {
			works=to==1;
		}
		else if (from<=3) {
			works=to<=3;
		}
		else works=true;
		cout<<(works?"YES\n":"NO\n");
	}
	return 0;
}