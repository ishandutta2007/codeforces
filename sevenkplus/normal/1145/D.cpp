#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

int main() {
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		a.pb(x);
	}
	cout << 2 + (a[2] ^ *min_element(a.begin(), a.end())) << endl;
	return 0;
}