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

int n, A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> A[i];
		bool flag = false;

		set<int> st;
		for (int i = n; i > 0; i--) {
			if (st.find(A[i]) != st.end()) {
				cout << i << endl;
				flag = true;
				break;
			}

			st.insert(A[i]);
		}

		if (!flag) cout << 0 << endl;
	}
	return 0;
}