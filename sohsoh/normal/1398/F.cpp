#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, A[MAXN], B[MAXN], R[MAXN], tof[MAXN];
set<int> st;
string s;
vector<int> ind[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	for (int i = n - 1; i >= 0; i--) {
		tof[i] = 1e7;
		if (s[i] == '0') B[i] = 0, A[i] = A[i + 1] + 1;
		else if (s[i] == '1') A[i] = 0, B[i] = B[i + 1] + 1;
		else A[i] = A[i + 1] + 1, B[i] = B[i + 1] + 1;
		R[i] = max(A[i], B[i]);
		ind[R[i]].push_back(i);
	}


	stack<int> ans;
	for (int x = n; x > 0; x--) {
		for (int i : ind[x]) {
			st.insert(i);
			for (int j = i; j > i - 100 && j >= 0; j--) tof[j] = min(tof[j], i);
		}

		int tans = 0, ind = 0;
		while (ind < n) {
			if (tof[ind] < n) {
				ind = tof[ind] + x;
				tans++;
				continue;
			}

			auto it = st.lower_bound(ind);
			if (it == st.end()) break;
			ind = *it + x;
			tans++;
		}

		ans.push(tans);
	}

	while (!ans.empty()) cout << ans.top() << sep, ans.pop();
	cout << endl;
	return 0;
}