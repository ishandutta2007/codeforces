
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T; cin>>T;
	while (T--) {
		int a, b, n; cin>>a>>b>>n;
		int ab=a^b;
		vector<int> ans(3, a);
		ans[1]=b; ans[2]=ab;
		cout<<ans[n%3]<<'\n';
	}

	return 0;
}