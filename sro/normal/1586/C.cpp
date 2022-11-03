#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N, M;
string s[1000005];

int main() {
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> s[i];
	vector<int> ls;
	for (int i = 1; i < M; ++i) {
		bool is = 0;
		for (int j = 1; j < N; ++j) if (s[j - 1][i] == 'X' && s[j][i - 1] == 'X') {
			is = 1; break;
		}
		if (is) ls.push_back(i);
	}
	int Q; cin >> Q;
	while (Q--) {
		int l, r; cin >> l >> r;
		--l; --r;
		int pos = upper_bound(ls.begin(), ls.end(), l) - ls.begin();
		if (pos < SZ(ls) && ls[pos] <= r) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}