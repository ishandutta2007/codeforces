#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	if (n % 2) {
		cout << "No\n";
		return 0;
	}

	vector <pair <int, int> > a(n);

	map <pair <int, int>, int> q;

	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	for (int i = 0; i < n / 2; i++) {
		auto A = a[i + 1], B = a[i];
		auto D = a[i + n / 2], C = a[(i + n / 2 + 1) % n];
		pair <int, int> v = {A.x - B.x, A.y - B.y}, u = {C.x - D.x, C.y - D.y};
		if (v.x != -u.x || v.y != -u.y) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";

}