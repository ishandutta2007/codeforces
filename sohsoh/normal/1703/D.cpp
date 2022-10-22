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

string S[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		
		set<string> st;
		for (int i = 1; i <= n; i++) {
			cin >> S[i];
			st.insert(S[i]);
		}

		for (int i = 1; i <= n; i++) {
			string b = S[i], a = "";
			bool flag = false;
			while (!b.empty()) {
				flag |= (st.find(b) != st.end() && st.find(a) != st.end());
				a.push_back(b.front());
				b.erase(b.begin());
			}

			cout << int(flag);
		}

		cout << endl;
	}
	return 0;
}