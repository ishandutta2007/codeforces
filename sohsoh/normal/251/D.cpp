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

const ll MAXN = 1e5 + 10;
const ll LOG = 62;

ll n, A[MAXN], s, ans[MAXN];
pair<ll, vector<int>> f[LOG];
int cnt[MAXN];

inline void wtf(vector<int>& vec) {
	vector<int> tvec;
	for (int e : vec)
		cnt[e] ^= 1;

	for (int e : vec) {
		if (cnt[e])
			tvec.push_back(e);
		
		cnt[e] = 0;
	}

	vec = tvec;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		s ^= A[i];
	}

	vector<int> T;
	for (int i = LOG - 1; i >= 0; i--)
		if (!(s >> i & 1))
			T.push_back(i);
	for (int i = LOG - 1; i >= 0; i--)
		if (s >> i & 1)
			T.push_back(i);


	for (int i = 1; i <= n; i++) {
		ll x = A[i];
		vector<int> vec = {i};

		for (int j : T) {	
			if (x >> j & 1) {
				if (!f[j].X) {
					wtf(vec);
					f[j] = {x, vec};
					break;
				}

				x ^= f[j].X;
				for (int e : f[j].Y)
					vec.push_back(e);
			}
		}

	}

	vector<int> st;
	ll x = 0;
	for (int i : T) {	
		if (x >> i & 1) continue;
		if (f[i].X) {
			x ^= f[i].X;
			for (int e : f[i].Y)
				st.push_back(e);
		}
	}

	for (int e : st)
		ans[e] ^= 1;

	for (int i = 1; i <= n; i++)
		cout << ans[i] + 1 << sep;
	cout << endl;
	return 0;
}