#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	if (n == 1) {
		int x;
		cin >> x;
		cout << "1 1\n";
		cout << "0\n";
		cout << "1 1\n";
		cout << "0\n";
		cout << "1 1\n";
		cout << -x << "\n";
		return 0;
	}
	vector <int> a(n);
	vector <pair <int, int> > res;
	for (int i = 0; i < n - 1; ++i) {
		int x;
		cin >> x;
		x = -x;
		int b = n - x % n;
		assert((x + b) % n == 0);
		int a = (x + b) / n - b;
		res.pb({a, b}); 
	}
	res.pb({0, 0});
	cout << "1 " << n << "\n";
	for (int i = 0; i < n; ++i) {
		cout << res[i].x * n << " ";
	}
	cout << "\n";
	cout << "1 " << n - 1 << "\n";
	for (int i = 0; i < n - 1; ++i) {
		cout << res[i].y * (n - 1) << " ";
	}
	cout << "\n";
	cout << n << " " << n << "\n";
	int x;
	cin >> x;
	cout << -x << "\n";
}