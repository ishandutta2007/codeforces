#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a + c <= b) {
		cout << "0\n";
		return;
	}
	int d = max(1, a - b - c);
	int e = a + c - b;
	if (e % 2 != d % 2) d++;
	cout << (e - d) / 2 + 1 << "\n";
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

}