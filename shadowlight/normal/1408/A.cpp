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
	int n;
	cin >> n;
	vector <int> a(n), b(n), c(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	vector <int> p(n);
	p[0] = a[0];
	for (int i = 1; i < n - 1; ++i) {
		if (a[i] == p[i - 1]) {
			p[i] = b[i]; 
		} else {
			p[i] = a[i];
		}
	}
	if (a[n - 1] != p[0] && a[n - 1] != p[n - 2]) {
		p[n - 1] = a[n - 1];
	} else if (b[n - 1] != p[0] && b[n - 1] != p[n - 2]) {
		p[n - 1] = b[n - 1];
	} else {
		p[n - 1] = c[n - 1];
	}
	for (int i = 0; i < n; ++i) {
		cout << p[i] << " ";
	}
	cout << "\n";
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
	for (int i = 0; i < t; ++i) {
		solve();
	}

}