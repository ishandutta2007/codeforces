#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pii> stuff;
	int n;
	cin >> n;
	int a, b, c, d;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d;
		stuff.push_back(pii(0-(a+b+c+d), i+1));
	}
	sort(stuff.begin(), stuff.end());
	for (int i = 0; i < n; i++) {
		if (stuff[i].second == 1) cout << i+1 << endl;
	}
	
}