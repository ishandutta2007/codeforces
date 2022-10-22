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

int n, k;
set<int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		st.clear();
		cin >> n >> k;
		bool flag = false;
	
		while (n--) {
			int x;
			cin >> x;
			flag |= st.find(x + k) != st.end() || st.find(x - k) != st.end();
			st.insert(x);
		}

		cout << (flag ? "YES" : "NO") << endl;
	}

	return 0;
}