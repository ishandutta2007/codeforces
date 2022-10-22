// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll LOG = 30;

int n, A[MAXN];
map<vector<int>, int> mp;
vector<int> v;

inline int G(int a, int b) {
	return __builtin_popcount(a) - __builtin_popcount(b);
}

inline vector<int> F(int x) {
	vector<int> ans;
	for (int i = 2; i <= n; i++)
		ans.push_back(G(A[i] ^ x, A[i]) - G(A[i - 1] ^ x, A[i - 1]));
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];

	int MASK = (1 << 15);
	for (int i = 0; i < MASK; i++) mp[F(i)] = i;
	
	vector<int> b;
	for (int i = 2; i <= n; i++)
		b.push_back(G(A[i], A[i - 1]));
	
	for (int i = 0; i < MASK; i++) {
		int x = (i << 15);
		vector<int> v = F(x);
		for (int j = 0; j < n - 1; j++) v[j] = -(b[j] + v[j]);
		
		auto it = mp.find(v);
		if (it != mp.end()) return cout << (x ^ (it -> Y)) << endl, 0;
	}

	cout << -1 << endl;
	return 0;
}