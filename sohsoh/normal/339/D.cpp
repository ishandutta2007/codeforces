// Sohsoh84 :)))
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

int A[MAXN], n, sg[MAXN], m;

void Build(int L = 1, int R = n, int v = 1) {
	if (L == R) sg[v] = A[L];
	else {
		int mid = (L + R) >> 1;
		Build(L, mid, v << 1);
		Build(mid + 1, R, v << 1 | 1);
		if (__builtin_ctz(R - L + 1) & 1) sg[v] = sg[v << 1] | sg[v << 1 | 1];
		else sg[v] = sg[v << 1] ^ sg[v << 1 | 1];
	}
}

void Update(int ind, int val, int L = 1, int R = n, int v = 1) {
	if (L == R) {
		A[L] = sg[v] = val;
		return;
	}

	int mid = (L + R) >> 1;
	if (ind <= mid) Update(ind, val, L, mid, v << 1);
	else Update(ind, val, mid + 1, R, v << 1 | 1);

	if (__builtin_ctz(R - L + 1) & 1) sg[v] = sg[v << 1] | sg[v << 1 | 1];
	else sg[v] = sg[v << 1] ^ sg[v << 1 | 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	n = (1 << n);
	for (int i = 1; i <= n; i++) cin >> A[i];

	Build();
	while (m--) {
		int p, b;
		cin >> p >> b;
		Update(p, b);
		cout << sg[1] << endl;
	}
	return 0;
}