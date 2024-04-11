#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; cin>>T;
	while (T--) {
		int n, x, a, b; cin>>n>>x>>a>>b;
		cout<<min(n-1, abs(a-b)+x)<<endl;
	}
	return 0;
}