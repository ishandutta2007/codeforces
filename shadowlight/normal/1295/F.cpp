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
const int N = 57;

void add(int &x, int y) {
	x += y;
	if (x >= MOD) {
		x -= MOD;
	}
	if (x < 0) {
		x += MOD;
	}
}

int power(int a, int k) {
	if (!k) {
		return 1;
	}
	int b = power(a, k / 2);
	b = b * (ll) b % MOD;
	if (k % 2) {
		return a * (ll) b % MOD;
	} else {
		return b;
	}
}

int rev(int a) {
	return power(a, MOD - 2);
}

int rv[N];

int C(int n, int k) {
	if (!k) {
		return 1;
	}
	return C(n, k - 1) * (ll) (n - k + 1) % MOD * rv[k] % MOD;
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < N; i++) {
		rv[i] = rev(i);	
	}

	int n;
	cin >> n;
	vector <pair <int, int> > a(n);
	set <int> q;
	q.insert(0);
	int bot = 1;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		a[i] = {l, r};
		q.insert(l);
		q.insert(r + 1);
		bot = bot * (ll) (r - l + 1) % MOD;
	}
	reverse(a.begin(), a.end());
	vector <int> t;
	for (auto x : q) {
		t.pb(x);
	}
	vector <vector <int> > cnt(n + 1, vector <int> (t.size(), 0));
	cnt[0][0] = 1;
	for (int k = 1; k < (int) t.size(); k++) {
		int l = t[k - 1], r = t[k] - 1;
		int len = r - l + 1;
		for (int i = 0; i < n; i++) {
			add(cnt[i][k], cnt[i][k - 1]);
			for (int j = i; j < n; j++) {
				int ln = a[j].x, rn = a[j].y;
				if (ln > r || rn < l) break;
				//cout << l << " " << ln << " " << rn << " " << r << endl;
				assert(ln <= l && r <= rn);
				int now = j - i + 1;
				add(cnt[j + 1][k], cnt[i][k - 1] * (ll) C(len + now - 1, now) % MOD);
			}
		}
		add(cnt[n][k], cnt[n][k - 1]);
	}
	int res = cnt[n][t.size() - 1];
	cout << res * (ll) rev(bot) % MOD << "\n";
}