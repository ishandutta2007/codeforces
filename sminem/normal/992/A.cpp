#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	set<int> s;
	while (n--) {
		int x;
		cin >> x;
		if (x)
			s.insert(x);
	}
	cout << s.size();
}