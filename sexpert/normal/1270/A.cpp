#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n, a, b, x;
		cin >> n >> a >> b;
		bool w = false;
		for(int i = 0; i < n; i++) {
			cin >> x;
			if(i < a && x == n)
				w = true;
		}
		cout << (w ? "YES" : "NO") << '\n';
	}
}