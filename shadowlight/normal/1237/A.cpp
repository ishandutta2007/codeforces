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
	vector <int> a(n);
	vector <bool> odd(n, false);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) {
			cout << a[i] / 2 << "\n";
		} else {
			odd[i] = true;
			int x = a[i] / 2;
			if (a[i] < 0) {
				if (sum) {
					cout << x - 1 << "\n";
					sum--;
				} else {
					cout << x << "\n";
					sum++;
				}
			} else {
				if (sum) {
					cout << x << "\n";
					sum--;
				} else {
					cout << x + 1 << "\n";
					sum++;
				}
			}
		}
	}
}