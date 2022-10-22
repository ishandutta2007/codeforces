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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, s1, s2;
vector<int> v, v_s;
int lz[MAXN], sg[MAXN];

inline void Push(int v) {
	if (lz[v]) {
		sg[v] = lz[v];
		lz[v << 1] = lz[v];
		lz[v << 1 | 1] = lz[v];
		lz[v] = 0;
	}
}

void Update(int v, int L, int R, int ql, int qr, int val) {
	Push(v);
	if (qr < ql) return;
	if (ql == L && qr == R) {
		lz[v] = val;
		Push(v);
		return;	
	}

	int mid = (L + R) >> 1;
	Update(v << 1, L, mid, ql, min(qr, mid), val);
	Update(v << 1 | 1, mid + 1, R, max(ql, mid + 1), qr, val);
	sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
} 

int Query(int v, int L, int R, int ql, int qr) {
	Push(v);
	if (qr < ql) return 0;
	if (ql == L && qr == R) return sg[v];
	
	int mid = (L + R) >> 1;
	return max(Query(v << 1, L, mid, ql, min(qr, mid)), Query(v << 1 | 1, mid + 1, R, max(ql, mid + 1), qr));
}

int ind(int p) {
	return lower_bound(all(v_s), p) - v_s.begin() + 1;
}

bool solve(int mx) {
	memset(lz, 0, sizeof lz);
	memset(sg, 0, sizeof sg);
	Update(1, 1, n, ind(s1), ind(s1), 2);
	for (int i = 2; i < v.size(); i++) {
		int t = 1;
		if (abs(v[i] - v[i - 1]) <= mx && Query(1, 1, n, 1, n) >= 2) t = 2;

		Update(1, 1, n, ind(v[i] + mx + 1), n, 1);
		Update(1, 1, n, 1, ind(v[i] - mx) - 1, 1);
		if (t == 2) Update(1, 1, n, ind(v[i - 1]), ind(v[i - 1]), 2); 
	}

	if (Query(1, 1, n, 1, n) > 1) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> s1 >> s2;
	
	v.push_back(s1);
	v.push_back(s2);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	v_s = v;
	sort(all(v_s));
	n = v.size();

	int L = abs(s2 - s1), R = int(1e9);
	while (L < R) {
		int mid = (L + R) >> 1;
		if (solve(mid)) R = mid;
		else L = mid + 1;
	}

	cout << L << endl;
	return 0;
}