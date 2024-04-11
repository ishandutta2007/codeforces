#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define int ll
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 2e5 + 10;
int a[MAXN];
int n;

void read() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

map<pair<int, int>, int> group;
int cnt[MAXN];
ll fans;

void add(int s, int t, int u) {
	group[{s, t}] = u;
	cnt[u]++;
	if (cnt[u] <= a[u])
		fans--;
}

void del(int s, int t) {
	int u = group[{s, t}];
	cnt[u]--;
	if (cnt[u] < a[u])
		fans++;
	group.erase({s, t});
}

ll get_ans() {
	return fans;
}

vector<ll> ans;

void run() {
	fans = 0;
	for (int i = 0; i < n; i++)
		fans+=a[i];
	int q;
	cin >> q;
	set<pair<int, int> > have;
	while(q--) {
		/*cout << "cnt = " << endl;
		for (int i = 0; i < n; i++)
			cout << cnt[i] << " ";
		cout << endl;
		cout << "fans = " << fans << endl;
		cout << endl;*/

		int s, t, u;
		cin >> s >> t >> u;
		if (have.count(make_pair(s, t))) {
			del(s, t);
			have.erase(make_pair(s, t));
		}
		if (u != 0) {
			u--;
			add(s, t, u);
			have.insert(make_pair(s, t));
		}
		ans.push_back(get_ans());
	}
}

void write() {
	for (auto i : ans)
		cout << i << "\n";
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