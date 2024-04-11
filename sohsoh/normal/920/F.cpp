#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, A[MAXN], D[MAXN];
ll fen[MAXN];
map<int, int> st;

inline ll Sum(int ind) {
	ll ans = 0;
	for (++ind; ind > 0; ind -= ind & -ind) 
		ans += fen[ind];
	return ans;
}

inline ll Sum(int L, int R) {
	return Sum(R) - Sum(L - 1);
}

inline void Add(int ind, int val) {
	for (++ind; ind < MAXN; ind += ind & -ind)
		fen[ind] += val;
}

inline void Reset(int ind, int val) {
	int t_val = Sum(ind, ind);
	Add(ind, val - t_val);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 1; i < MAXN; i++)
		for (int j = i; j < MAXN; j += i)
			D[j]++;
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		Add(i, A[i]);
		st.insert({i, A[i]});
	}

	while (m--) {
		int t, L, R;
		cin >> t >> L >> R;
		if (t == 2) {
			cout << Sum(L, R) << endl;
			continue;
		}


		auto it = st.lower_bound(L);	
		while (it != st.end() && it -> X <= R)
			it -> Y = D[it -> Y], Reset(it -> X, it -> Y), it++;

		int ind = L;
		while (ind <= R) {
			auto it = st.lower_bound(ind);
			if (it == st.end() || it -> X > R) break;

			if (D[it -> Y] == it -> Y) {
				ind = it -> X + 1;
				st.erase(it);
			} else ind = it -> X + 1;
		}
	}
	return 0;
}