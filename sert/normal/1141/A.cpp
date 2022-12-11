#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
	int n, m;
	cin >> n >> m;
	if (m % n) {cout << "-1\n"; return;}
	int ans = 0;
	while (m % n == 0) { n *= 2; ans++; }
	n /= 2;
	while (m % n == 0) { n *= 3; ans++; }
	n /= 3;
	cout << (n == m ? ans - 2 : -1) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
#ifdef MADE_BY_SERT
	int T = 3;
	for (int i = 1; i < T; i++) solve();	
#endif
}