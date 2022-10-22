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
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		bool can = true;
		cout << n << "\n";
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			if (s[i] > s[i % k]) {
				can = false;
			} else if (s[i] < s[i % k]) {
				s[i] = s[i % k];
				break;
			}
		}
		if (can) {
			for (int i = 0; i < n; i++) {
				cout << s[i % k];
			}
			return 0;
		}
		for (int i = k - 1; i >= 0; i--) {
			if (s[i] != '9') {
				s[i]++;
				break;
			} else {
				s[i] = '0';
			}
		}
		for (int i = 0; i < n; i++) {
			cout << s[i % k];
		}
	}