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

int A[MAXN], B[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		vector<int> v1, v2;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> A[i];

		for (int i = 1; i <= n; i++) {
			char c;
			cin >> c;
			if (c == '0') v1.push_back(i);
			else v2.push_back(i);
		}

		sort(all(v1), [] (int i, int j) {
			return A[i] < A[j];
		});

		sort(all(v2), [] (int i, int j) {
			return A[i] < A[j];
		});

		v1.insert(v1.end(), all(v2));
		for (int i = 0; i < int(v1.size()); i++)
			B[v1[i]] = i + 1;
	
		for (int i = 1; i <= n; i++)
			cout << B[i] << sep;
		cout << endl;
	}
	return 0;
}