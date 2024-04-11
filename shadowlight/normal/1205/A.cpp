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
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	deque <int> t;
	for (int i = 1; i < 2 * n; i += 2) {
		t.push_back(i);
	}
	vector <int> a;
	for (int i = 0; i < n; i++) {
		if (i % 2) {
			a.push_back(t.back() + 1);
			t.pop_back();
		} else {
			a.push_back(t.front());
			t.pop_front();
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] % 2) {
			a.push_back(a[i] + 1);
		} else {
			a.push_back(a[i] - 1);
		}
	}
	if (n % 2) {
		cout << "YES\n";
		for (int x : a) {
			cout << x << " ";
		}
		cout << "\n";
	} else {
		cout << "NO\n";
	}
}