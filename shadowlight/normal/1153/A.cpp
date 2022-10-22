#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = 1e9 + 7;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, t;
	cin >> n >> t;
	int tm = INF;
	int id = -1;
	for (int i = 0; i < n; i++) {
		int s, d;
		cin >> s >> d;
		while (s < t) s += d;
		if (s < tm) {
			tm = s;
			id = i;
		}
	}
	cout << id + 1 << "\n";
}