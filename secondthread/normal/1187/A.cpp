#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T; cin>>T;
	while(T--) {
		int n, s, t; cin>>n>>s>>t;
		int empty=n-min(s, t);
		cout<<empty+1<<'\n';
	}

	return 0;
}