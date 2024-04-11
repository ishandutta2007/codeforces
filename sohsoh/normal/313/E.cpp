#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int n, m, cnt_a[MAXN], cnt_b[MAXN];
stack<int> st;
queue<int> q;
vector<int> ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cnt_a[x]++;
	}

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cnt_b[x]++;
	}

	for (int i = 0; i < m; i++) {
		while (cnt_a[i]--)
			st.push(i);

		while (cnt_b[m - i - 1]--) {
			if (!st.empty()) {
				ans.push_back(st.top() + m - i - 1);
				st.pop();
			} else q.push(m - i - 1);
		}
	}

	while (!st.empty()) {
		ans.push_back(st.top() + q.front());
		st.pop();
		q.pop();
	}

	for (int& e : ans) e %= m;
	sort(all(ans), greater<int>());

	for (int e : ans) cout << e << sep;
	cout << endl;
	return 0;
}