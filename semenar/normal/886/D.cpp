#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(X) X.begin(), X.end()
#define sz(X) ((int)X.size())

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef string str;

typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vs words(n);
	for (int i = 0; i < n; i++) cin >> words[i];

	// Check each string for repeating letters
	bool good_strings = true;
	for (auto w : words) {
		vb uchars(26);
		for (auto ch : w) {
			if (uchars[ch - 'a']) good_strings = false;
			uchars[ch - 'a'] = true;
		}
	}

	if (!good_strings) {
		cout << "NO" << endl;
		return 0;
	}

	// Make links
	vi links(26, -1);
	vb here(26);
	for (auto w : words) {
		for (auto ch : w) {
			here[ch - 'a'] = true;
		}
	}
	for (auto w : words) {
		for (int i = 1; i < sz(w); i++) {
			if (links[w[i - 1] - 'a'] >= 0 && links[w[i - 1] - 'a'] != w[i] - 'a') {
				cout << "NO" << endl;
				return 0;
			}
			links[w[i - 1] - 'a'] = w[i] - 'a';
			here[w[i] - 'a'] = false;
		}
	}

	// Check for circular dependencies
	for (int i = 0; i < 26; i++) {
		int x = i;
		int cnt = 0;
		while (x != -1 && cnt < 50) {
			x = links[x];
			cnt++;
		}
		if (cnt == 50) {
			cout << "NO" << endl;
			return 0;
		}
	}

	// Check for bamboo
	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			if (links[i] >= 0 && links[i] == links[j]) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	str ans;
	for (int i = 0; i < 26; i++) {
		if (!here[i]) continue;
		int x = i;
		while (x != -1) {
			ans.pb(x + 'a');
			here[x] = false;
			x = links[x];
		}
	}

	cout << ans << endl;
}