#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MOD = 998244353;

void solve() {
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	vector <int> b(k);
	vector <int> pos(n);

	vector <int> qq(n);
	iota(all(qq), 0);
	set <int> q;
	for (int x : qq) {
		q.insert(x);
	}
	
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
		pos[a[i]] = i;
	}

	vector <int> positions;

	vector <int> can_delete(n, 1);

	for (int i = 0; i < k; ++i) {
		cin >> b[i];
		--b[i];
		//cout << b[i] << " " << pos[b[i]] << "\n";
		can_delete[pos[b[i]]] = false;
		positions.pb(pos[b[i]]);
	}

	int res = 1;

	for (int x : positions) {
		int pr = -1, nxt = -1;
		
		auto it = q.lower_bound(x);
		assert(it != q.end());
		++it;
		if (it != q.end()) {
			nxt = *it;
		}
		--it;
		if (it != q.begin()) {
			pr = *(--it);
		}

		if (nxt == -1 || pr == -1) {
			int val = nxt + pr + 1;
			if (val == -1 || !can_delete[val]) {
				res = 0;
				break;
			}
			q.erase(val);
		} else if (!can_delete[nxt] || !can_delete[pr]) {
			if (!can_delete[nxt] && !can_delete[pr]) {
				res = 0;
				break;
			}
			int val = (can_delete[nxt] ? nxt : pr);
			q.erase(val);
		} else {
			res = res *  2 % MOD;
			q.erase(pr);
		}
		can_delete[x] = true;
		/*cout << res << "\n";
		for (int x : q) {
			cout << x << " ";
		}
		cout << "\n";
		cout << "==============\n";*/
	}
	cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}