#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		multiset<char> st;
		int n, k;
		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			st.insert(c);
		}

		for (int i = 0; i < k; i++) {
			char c = 'a';
			int cnt = 0;

			while (cnt < n / k) {
				auto it = st.find(c);
				if (it != st.end()) st.erase(it), c++;
				else break;
				cnt++;
			}

			cout << c;
		}

		cout << endl;
	}
	return 0;
}