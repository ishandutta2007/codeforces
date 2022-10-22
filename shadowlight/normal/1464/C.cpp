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
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	ll T;
	cin >> T;

	ll res = 0;

	string s;
	cin >> s;
	vector <int> counts(27, 0);
	for (int i = 0; i < n - 2; ++i) {
		int k = s[i] - 'a';
		res += (1 << k);
		++counts[k + 1];
	}

	res -= (1 << (s[n - 2] - 'a'));
	res += (1 << (s[n - 1] - 'a'));

	if (res < T) {
		cout << "No\n";
		return 0;
	}

	ll delta = res - T;

	for (int i = 26; i >= 0; --i) {
		while (counts[i] && (1 << i) <= delta) {
			delta -= (1 << i);
			--counts[i];
		}
	}
	if (delta) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}
}