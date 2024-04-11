// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

pll Q[MAXN];
int n, m, ind[MAXN], sg[MAXN], ans[MAXN], A[MAXN];
vector<int> L[MAXN], R[MAXN], E[MAXN];

void Update(int ind, int val, int L = 1, int R = n, int v = 1) {
	if (L == R) sg[v] += val;
	else {
		int mid = (L + R) >> 1;
		if (ind <= mid) Update(ind, val, L, mid, v << 1);
		else Update(ind, val, mid + 1, R, v << 1 | 1);
		sg[v] = sg[v << 1] + sg[v << 1 | 1];
	}
}

int Query(int QL, int QR, int L = 1, int R = n, int v = 1) {
	if (QR < QL) return 0;
	if (L == QL && R == QR) return sg[v];

	int mid = (L + R) >> 1;
	return Query(QL, min(QR, mid), L, mid, v << 1) + 
		Query(max(QL, mid + 1), QR, mid + 1, R, v << 1 | 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {	
		cin >> A[i];
		ind[A[i]] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = A[i]; j <= n; j += A[i]) {
			int k = ind[j];
			if (k < i) E[k].push_back(i);
			else E[i].push_back(k);
		}
	}

	for (int i = 1; i <= m; i++) {
		int l, r;
		cin >> l >> r;
		L[l].push_back(i), R[r].push_back(i);
		Q[i] = {l, r};
	}
	
	for (int i = 1; i <= n; i++) {
		for (int q : L[i]) ans[q] -= Query(Q[q].X, Q[q].Y);
		for (int e : E[i]) Update(e, 1);
		for (int q : R[i]) ans[q] += Query(Q[q].X, Q[q].Y);	
	}

	for (int i = 1; i <= m; i++) cout << ans[i] << endl;
	return 0;
}