#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const int maxn=100001;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin>>n>>m;
	if (m*2>=n) {
		cout<<n-m<<endl;
	}
	else {
		int ans=1;
		ans=max(ans, m);
		cout<<ans<<endl;
	}


	return 0;
}