//In the name of God
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int n,k; cin >> n >> k;
	int cnt = n - k + n - 1;
	while(k--) {
		vector<int> v;
		int m; cin >> m;
		for(int i = 0; i < m;i++) {
			int p; cin >> p;
			v.push_back(p);
		}
		sort(v.begin(),v.end());
		bool f = (v[0] == 1);
		for(int i = 1; i < m;i++) {
			if(v[i] == v[i-1] + 1 && f) cnt-=2;
			else f = 0; 
		}
	}
	cout << cnt << '\n';
	return 0;
}