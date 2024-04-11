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
	map<int, int> A;
	int n;
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		A[x] = max(A[x], y);
	}
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		A[x] = max(A[x], y);
	}
	ll S = 0;
	for (auto i : A) S += i.se;
	cout << S << endl;
	return 0;
}