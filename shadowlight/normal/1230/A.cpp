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
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a[4];
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % 2) {
		cout << "NO\n";
		return 0;
	}
	for (int i = 0; i < 4; i++) {
		if (a[i] == sum / 2) {
			cout << "YES\n";
			return 0;
		}
		for (int j = i + 1; j < 4; j++) {
			if (a[i] + a[j] == sum / 2) {
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
}