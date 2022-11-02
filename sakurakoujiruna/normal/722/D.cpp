#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	set <int> s;
	for(int i = 0; i < n; i ++) {
		int x; cin >> x;
		s.insert(x);
	}
	while(true) {
		int t = *s.rbegin();
		int f = -1;
		for(int x = t / 2; x; x /= 2)
			if(!s.count(x)) {
				f = x;
				break;
			}
		if(f == -1)
			break;
		s.insert(f);
		s.erase(t);
	}
	for(auto x : s)
		cout << x << ' ';
	cout << '\n';
	return 0;
}