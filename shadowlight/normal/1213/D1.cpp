#include <bits/stdc++.h>
#define ll long long
#define db long double
#define data suka
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, k;

const int N = 2e5 + 7;
const int INF = 1e9 + 7;

int now_sum = 0;

vector <int> merge(vector <int> &a, vector <int> &b, int zeroes) {
	vector <int> c;
	zeroes = min(zeroes, k);
	for (int i = 0; i < zeroes; i++) {
		c.push_back(0);
	}
	now_sum = 0;
	int n = a.size(), m = b.size();
	int i = 0, j = 0;
	while (c.size() < k && (i < n || j < m)) {
		if (i == n || (j != m && a[i] > b[j])) {
			c.push_back(b[j++] + 1);
		} else {
			c.push_back(a[i++] + 1);
		}
		now_sum += c.back();
	}
	a.clear(), b.clear();
	return c;
}

int cnt[N];
vector <int> data[2 * N];

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	int res = INF;
	for (int i = N - 1; i >= 0; i--) {
		data[i] = merge(data[(!i ? 2 * N - 1 : 2 * i)], data[2 * i + 1], cnt[i]);
		if (data[i].size() == k) {
			res = min(res, now_sum);
		}
	}
	cout << res << "\n";
}