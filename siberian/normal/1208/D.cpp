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
}

vector <int> ans;

const int MAXN = 2e5 + 10;
int tree[MAXN];

void add(int pos, int val) {
	for (; pos < MAXN; pos = (pos | (pos + 1)))
		tree[pos] += val;
}

int get(int r) {
	int ans = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		ans += tree[r];
	return ans;
}

void run() {
	ans.resize(n);
	for (int i = 1; i <= n; i++)
		add(i, i);


	//cout << "tree = " << endl;
	//for (int j = 1; j <= n; j++)
	//	cout << get(j) << " ";
	//cout << endl;

	set <int> num;
	for (int i = 1; i <= n; i++)
		num.insert(i);

	for (int i = n - 1; i >= 1; i--) {
		int l = -1, r = n; 
		while (l < r - 1) {
			int mid = (l + r) / 2;
			if (get(mid) <= a[i]) {
				l = mid;
			}
			else {
				r = mid;
			}
		}
		//assert(get(r) >= a[i]);
		//cout << "r = " << r << " get(r) = " << get(r) << " a[i] = " << a[i] << endl;
		l++;
		ans[i] = l;
		add(l, -l);
		num.erase(l);
		//cout << "tree = " << endl;
		//for (int j = 1; j <= n; j++)
		//	cout << get(j) << " ";
		//cout << endl;
	}
	ans[0] = *num.begin();
}

void write() {
	for (auto i : ans)
		cout << i << " ";
	cout << endl;
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