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
int F[MAXN];

set<int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;

	ll tot = 0;
	for (int i = 1; i <= n; i++) {
		st.insert(i);
		for (int j = i + i; j <= n; j += i)
			F[j]++;
		
		tot += F[i];
	}

	if (tot < k) return cout << "No" << endl, 0;
	while (tot - F[n] >= k) {
		st.erase(n);
		tot -= F[n--];
	}

	for (int i = 1; i <= n; i++) {
		if (F[i] != 1) continue;
		if (tot - n / i >= k) {
			st.erase(i);
			tot -= n / i;
		}
	}

	assert(tot == k);
	cout << "Yes" << endl << st.size() << endl;
	for (int e : st)
		cout << e << sep;
	cout << endl;
	return 0;
}