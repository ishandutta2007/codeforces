#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll
const int MAXN = 1e6 + 10;

int n;
int a[MAXN];

void read() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

ll pref[MAXN];

void build() {
	pref[0] = 0;
	for (int i = 1; i <= n; i++)
		pref[i] = pref[i - 1] + a[i - 1];
}

ll get(int l, int r) {
	return pref[r] - pref[l - 1];
}

bool check(pair<int, int> a, pair<int, int> b) {
	return get(a.first, a.second) * (b.second - b.first + 1) < get(b.first, b.second) * (a.second - a.first + 1);
}

int nxt[MAXN];

void calc() {
	vector<pair<int, int> > st;
	nxt[n] = n;
	st.push_back({n, n});
	for (int i = n - 1; i >= 1; i--) {
		st.push_back({i, i});
		while (st.size() > 1) {
			auto a = st[st.size() - 2];
			auto b = st[st.size() - 1];
			a.first = b.first;
			if (check(a, b)) {
				st.pop_back();
				st.pop_back();
				st.push_back(a);
				continue;
			}
			break;
		}
		nxt[i] = st.back().second;
	}
	/*cout << "nxt = " << endl;
	for (int i = 1; i <= n; i++)
		cout << nxt[i] << " ";
	cout << endl;*/
}

ld ans[MAXN];

void make_ans() {
	int pos = 1;
	while (pos <= n) {
		//cout << "pos " << pos << endl;
		ans[pos] = (ld)get(pos, nxt[pos]) / (nxt[pos] - pos + 1);
		for (int i = pos + 1; i <= nxt[pos]; i++)
			ans[i] = ans[i - 1];
		pos = nxt[pos] + 1;
	}
}

void run() {
	build();
	calc();
	make_ans();
}

void write() {
	cout.precision(12);
	cout.setf(ios::fixed);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}