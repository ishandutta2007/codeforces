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
const ll INF = 1e9 + 1; // ?

int n, k, d, A[MAXN], sg[MAXN], lz[MAXN];
map<int, int> mp;

inline void push(int v) {
	sg[v] += lz[v];
	if ((v << 1 | 1) < MAXN) {
		lz[v << 1] += lz[v];
		lz[v << 1 | 1] += lz[v];
	}

	lz[v] = 0;
}

void update(int ql, int qr, int val, int l = 1, int r = n, int v = 1) {
	push(v);
	//if (v == 1) cerr << "update " << ql << sep << qr << sep << val << endl;
	if (ql > r || qr < l) return;
	if (ql <= l && qr >= r) {
		lz[v] += val;
		push(v);
		return;
	}

	int mid = (l + r) >> 1;
	update(ql, qr, val, l, mid, v << 1);
	update(ql, qr, val, mid + 1, r, v << 1 | 1);
	sg[v] = min(sg[v << 1], sg[v << 1 | 1]);
}

int query(int l = 1, int r = n, int v = 1) {
	if (l == r) return l;

	push(v);
	push(v << 1);
	push(v << 1 | 1);

	int mid = (l + r) >> 1;
	if (sg[v << 1 | 1] <= k) return query(mid + 1, r, v << 1 | 1);
	return query(l, mid, v << 1);
}

void reset(int ind, int val, int l = 1, int r = n, int v = 1) {
	push(v);
	//if (v == 1) cerr << "reset " << ind << sep << val << endl;
	if (l == r) {
		sg[v] = val;
		return;
	}

	int mid = (l + r) >> 1;
	if (ind <= mid) reset(ind, val, l, mid, v << 1), push(v << 1 | 1);
	else reset(ind, val, mid + 1, r, v << 1 | 1), push(v << 1);
	sg[v] = min(sg[v << 1], sg[v << 1 | 1]);
}

inline int mod(int n) {
	return (n + int(1e9)) % d;
}

inline int fuck(int x) {
	x -= mod(x);
	return x / d;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k >> d;	
	for (int i = 1; i <= n; i++) cin >> A[i];
	
	if (d == 0) {
		pll f = {n, n};
		int lst = n;
		for (int i = n - 1; i > 0; i--) {
			if (A[i] != A[i + 1])
				lst = i;

			if (lst - i >= f.Y - f.X) f = {i, lst};
		}
	
		return cout << f.X << sep << f.Y << endl, 0;
	}

	memset(sg, INF, sizeof sg);
	int lst = n + 1;

	stack<int> mn_st, mx_st;	
	mn_st.push(n + 1);
	mx_st.push(n + 1);
	mn_st.push(n);
	mx_st.push(n);

	mp[A[n]] = n;

	reset(n, 0);
	pll ans = {n, n};

	for (int l = n - 1; l > 0; l--) {
		update(l, n, -1);
		reset(l, 0);

		if (mod(A[l]) != mod(A[l + 1])) {
			while (lst > l + 1) {
				lst--;			
				reset(lst, INF);
			}
		}

		int ind = mp[A[l]];
		mp[A[l]] = l;
		
		if (ind) {
			while (lst > ind) {
				lst--;
				reset(lst, INF);
			}
		}

		while (mn_st.top() < lst && A[mn_st.top()] > A[l]) {
			int ind = mn_st.top();
			mn_st.pop();
			update(ind, mn_st.top() - 1, fuck(A[ind]) - fuck(A[l]));
		}

		while (mx_st.top() < lst && A[mx_st.top()] < A[l]) {
			int ind = mx_st.top();
			mx_st.pop();
			update(ind, mx_st.top() - 1, fuck(A[l]) - fuck(A[ind]));
		}

		mn_st.push(l);
		mx_st.push(l);
		
		int r = query();
		if (r - l >= ans.Y - ans.X) ans = {l, r};
	}

	cout << ans.X << sep << ans.Y << endl;
	return 0;
}