#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const ll AD = (1LL << 50);

void solve() {
	int n;
	cin >> n;
	ll sum = 0, xorsum = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sum += x;
		xorsum ^= x;
	}
	ll value = AD;
	sum += AD;
	xorsum ^= AD;
	if (sum % 2) {
		sum++;
		value++;
		xorsum ^= 1;
	}
	ll sec = 2 * xorsum - sum;
	assert(sec % 2 == 0);
	cout << "3\n";
	cout << value << " " << sec / 2 << " " << sec / 2 << "\n";
	//cout << sum << " " << 2 * xorsum << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

}