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
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector <int> a1, a2;
	a1.pb(0);
	for (int i = 1; i < n; ++i) {
		if (!a1.size()) {
			a1.pb(i);
			continue;
		}
		if (a[a1.back()] == a[i]) {
			a2.pb(i);
			continue;
		}
		if (a2.size() && a[a2.back()] == a[i]) {
			a1.pb(i);
			continue;
		}
		if (i == n - 1) {
			a1.pb(i);
			continue;
		}
		if (a[i + 1] == a[a1.back()]) {
			a1.pb(i);
		} else {
			a2.pb(i);
		}
	}
	/*for (int x : a1) {
		cout << a[x] << " ";
	}
	cout << "\n";
	for (int x : a2) {
		cout << a[x] << " ";
	}
	cout << "\n";*/
	//cout << a1.size() << " " << a2.size() << endl;
	int res = (a1.size() >= 1) + (a2.size() >= 1);

	for (int i = 1; i < (int) a1.size(); ++i) {
		if (a[a1[i]] != a[a1[i - 1]]) {
			++res;
		}
	}
	for (int i = 1; i < (int) a2.size(); ++i) {
		if (a[a2[i]] != a[a2[i - 1]]) {
			++res;
		}
	}
	cout << res << "\n";

}