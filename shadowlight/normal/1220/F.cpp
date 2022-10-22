#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MAXN = 2e5 + 7;
const int INF = 1e9 + 7;

pair <int, int> t[2 * MAXN];
int n;

pair <int, int> get(int l, int r) {
	pair <int, int> res = {INF, INF};
	for (l += n, r += n; l <= r; l /= 2, r /= 2) {
		if (l % 2) res = min(res, t[l++]);
		if (r % 2 == 0) res = min(res, t[r--]);
	}
	return res;
}

pair <int, int> dfs(int l, int r, int h) {
	if (r - l < 0) {
		return {-1, -1};
	}
	if (r == l) {
		return {h, h};
	}
	auto t =  get(l, r);
	auto a = dfs(l, t.second - 1, h + 1);
	auto b = dfs(t.second + 1, r, h + 1);
	return {max(a.first, a.second), max(b.first, b.second)};
}

void build(vector <int> &a) {
	for (int i = 0; i < n; i++) {
		t[i + n] = {a[i], i};
	}
	for (int i = n - 1; i > 0; i--) {
		t[i] = min(t[2 * i], t[2 * i + 1]);
	}
}

pair <int, int> get_heights(int mid, vector <int> &a) {
	//cout << mid << "\n";
	vector <int> b(n, 0);
	for (int i = 0; i < n; i++) {
		b[(i + mid) % n] = a[i];
	}/*
	for (int x : b) {
		cout << x << " ";
	}
	cout << "\n";*/
	build(b);
	return dfs(0, n - 1, 1);
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector <int> a(n);
	int st = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		if (!a[i]) st = i;
	}
	vector <int> b(n, 0);
	for (int i = 0; i < n; i++) {
		b[i] = a[(i + st) % n];
	}
	a = b;
	int lt = 0, rt = n;
	while (rt - lt > 1) {
		int mid = (lt + rt) / 2;
		vector <int> b(n, 0);
		for (int i = 0; i < n; i++) {
			b[(i + mid) % n] = a[i];
		}
		build(b);
		auto t = get_heights(mid, a);
		if (t.first > t.second) {
			rt = mid;
		} else {
			lt = mid;
		}
	}
	auto res1 = get_heights(lt, a), res2 = get_heights(rt, a);
	int t1 = max(res1.first, res1.second), t2 = max(res2.first, res2.second);
	if (t1 < t2) {
		cout << t1 << " " << (st + n - lt) % n << "\n";
	} else {
		cout << t2 << " " << (st + n - rt) % n << "\n";
	}
}