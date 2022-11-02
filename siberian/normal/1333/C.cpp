#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;
vector<int> a;

void read() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
	for (int i = 1; i < n; i++)
		a[i] += a[i - 1];
}

map<int, int> cnt;
multiset<int> have;

void add(int pos) {
	if (have.find(cnt[a[pos]]) != have.end())
	have.erase(have.find(cnt[a[pos]]));
	cnt[a[pos]]++;
	have.insert(cnt[a[pos]]);
}

void del(int pos) {
	assert(have.find(cnt[a[pos]]) != have.end());
	have.erase(have.find(cnt[a[pos]]));
	cnt[a[pos]]--;
	have.insert(cnt[a[pos]]);
}

int l, r;

bool check() {
	/*cout << "l = " << l << " r = " << r << endl;
	cout << "cnt = " << endl;
	for (auto i : cnt)
		cout << i.first << " " << i.second << endl;
	cout << "have = " << endl;
	for (auto i : have)
		cout << i << " ";
	cout << endl;
	cout << endl;*/
	return (l == 0 ? cnt[0] == 0 : cnt[a[l - 1]] == 0) && (have.empty() || (*(--have.end()) <= 1));
}

int ans;

void run() {
	ans = 0;
	l = 0, r = 0;
	while (l < n) {
		while (r < n) {
			add(r);
			if (!check()) {
				del(r);
				break;
			}
			r++;
		}
		
		ans += r - l;
		//cout << l << " " << r << endl;
		if (r != l) {
			del(l);
		}
		l++;
		chkmax(r, l);
	}
}

void write() {
	cout << ans << endl;
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