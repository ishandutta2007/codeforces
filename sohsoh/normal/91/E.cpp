// orz ?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const int INF = 1e9; // 

ll A[MAXN], B[MAXN], n, q;
vector<pll> cv[MAXN];

void build(int l = 1, int r = n, int v = 1) {
	if (l == r) {
		cv[v] = {{-INF, l}};
		return;
	}

	vector<int> vec;
	for (int i = l; i <= r; i++) vec.push_back(i);
	sort(all(vec), [] (int i, int j) {
		return make_pair(B[i], A[i]) < make_pair(B[j], A[j]);				
	});

	for (int i : vec) {	
		if (cv[v].empty()) {	
			cv[v] = {{-INF, i}};
			continue;
		}

		int start = INF;
		while (!cv[v].empty()) {
			int ind = cv[v].back().Y;
			if (B[i] == B[ind]) {
				start = cv[v].back().X;
				cv[v].pop_back();
				continue;
			}
		
			int f = (A[ind] - A[i] + B[i] - B[ind] - 1) / (B[i] - B[ind]);
			if (f <= cv[v].back().X) {
				start = cv[v].back().X;
				cv[v].pop_back();
			} else {
				start = f;
				break;
			}
		}

		cv[v].push_back({start, i});
	}

	int mid = (l + r) >> 1;
	build(l, mid, v << 1);
	build(mid + 1, r, v << 1 | 1);
}

int query(int ql, int qr, int t, int l = 1, int r = n, int v = 1) {
	if (ql > r || qr < l) return ql;
	if (ql <= l && qr >= r) return prev(lower_bound(all(cv[v]), make_pair(t, INF))) -> Y;

	int mid = (l + r) >> 1;
	int i = query(ql, qr, t, l, mid, v << 1), j = query(ql, qr, t, mid + 1, r, v << 1 | 1);
	return A[i] + B[i] * t > A[j] + B[j] * t ? i : j;
}


int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i] >> B[i];

	build();
	while (q--) {
		int l, r, t;
		cin >> l >> r >> t;
		cout << query(l, r, t) << endl;
	}
	return 0;
}