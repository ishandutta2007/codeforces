#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
#define int ll
struct segment{
	int l, r;
	segment() {}
	segment(int a, int b) {
		l = a, r = b;
	}
};

int n;
vector<segment> a;

void read() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i.l >> i.r, i.l *= 2, i.r *= 2;
}

vector<int> now;

struct event{
	int x, type;
	event() {}
	event(int a, int b) {
		x = a, type = b;
	}
};

bool operator<(const event & a, const event & b) {
	return a.x < b.x;
}

void build_now() {
	vector<event> have;
	for (auto i : a)
		have.push_back({i.l, 1}), have.push_back({i.r + 1, -1});
	sort(all(have));
	int add = 0;
	int pos = 0;
	for (int i = 0; i < (int)now.size(); i++) {
		while (pos < have.size() && have[pos].x == i) {
			add += have[pos].type;
			pos++;
		}
		now[i] = add;
	}
}

vector<int> last, nxt;

void build_lr() {
	for (int i = 0; i < last.size(); i++) {
		if (i != 0)
			last[i] = last[i - 1];
		if (now[i] >= 2) 
			last[i] = i;
	}
	for (int i = nxt.size() - 1; i >= 0; i--) {
		if (i != nxt.size() - 1)
			nxt[i] = nxt[i + 1];
		if (now[i] >= 2)
			nxt[i] = i;
	}
}

vector<int> cnt;
int full = 0;

void build_cnt() {
	for (int i = 1; i < cnt.size(); i++) {
		cnt[i] = cnt[i - 1];
		if (now[i] == 1 && now[i - 1] != 1) {
			cnt[i]++;
		}
	}
	full = 1;
	for (int i = 1; i < now.size(); i++) {
		if (now[i] == 0 && now[i - 1] != 0)
			full++;
	}
}

void Unique() {
	vector<int> have;
	for (auto i : a) {
		have.push_back(i.l);
		have.push_back(i.l - 1);
		have.push_back(i.l + 1);

		have.push_back(i.r);
		have.push_back(i.r - 1);
		have.push_back(i.r + 1);
	} 
	sort(all(have));
	have.resize(unique(all(have)) - have.begin());
	for (auto &i : a) {
		i.l = lower_bound(all(have), i.l) - have.begin();
		i.r = lower_bound(all(have), i.r) - have.begin();
	}
	now.assign(have.size(), 0);
	last.assign(have.size(), -1);
	nxt.assign(have.size(), -1);
	cnt.assign(have.size(), 0);
}

void build() {
	Unique();
	build_now();
	build_lr();
	build_cnt();
}

int solve(int l, int r) {
	if (nxt[l] == -1 || nxt[l] > r) {
		if (now[l - 1] == 0 && now[r + 1] == 0)
			return full - 2;
		return full - 1;
	}
	int L = nxt[l];
	int R = last[r];
	int ans = full;
	if (now[l] == 1 && now[l - 1] != 0) ans++;
	if (now[r] == 1 && now[r + 1] != 0) ans++;
	ans += cnt[R] - cnt[L];
	return ans - 1;
}

int ans;

void run() {
	build();
	ans = 0;
	/*cout << "a = " << endl;
	for (auto i : a)
		cout << i.l << " " << i.r << endl;
	cout << endl;
	cout << "now = " << endl;
	for (auto i : now)
		cout << i << " ";
	cout << endl;*/
	for (int i = 0; i < n; i++) {
		chkmax(ans, solve(a[i].l, a[i].r));
	}
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		read();
		run();
		write();
	}
	return 0;
}