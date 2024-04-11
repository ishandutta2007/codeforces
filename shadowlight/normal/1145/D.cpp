#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = 1e9 + 7;

int main() {
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int> a(n);
	int mink = INF;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mink = min(mink, a[i]);
	}
	cout << 2 + (mink ^ a[2]) << "\n";
}