// \_()_/
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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

struct Node {
	int val = 0, pref = 0, suff = 0;
	Node *l = nullptr, *r = nullptr;
	bool full = false;

	Node(bool b) {
		if (b) {
			full = true;
			pref = suff = val = 1;
		}
	}

	Node(Node* l, Node* r) : l(l), r(r) {
		if (!l) return;
		val = max({l -> val, r -> val, l -> suff + r -> pref});
		pref = l -> pref + (l -> full ? r -> pref : 0);
		suff = r -> suff + (r -> full ? l -> suff : 0);
		full = r -> full && l -> full;
	}
};

Node* Build(int L, int R) {
	if (L == R) return new Node(false);
	int mid = (L + R) >> 1;
	return new Node(Build(L, mid), Build(mid + 1, R));
}

Node* Update(Node* v, int L, int R, int ind) {
	if (L == R) return new Node(true);
	int mid = (L + R) >> 1;
	if (ind <= mid) return new Node(Update(v -> l, L, mid, ind), v -> r);
	return new Node(v -> l, Update(v -> r, mid + 1, R, ind));
}

int Query(Node* v, int L, int R, int QL, int QR) {
	if (QL > QR) return 0;
	if (QL == L && QR == R) return v -> val;

	int mid = (L + R) >> 1;
	if (QR <= mid) return Query(v -> l, L, mid, QL, QR);
	if (QL > mid) return Query(v -> r, mid + 1, R, QL, QR);
	return max({Query(v -> l, L, mid, QL, mid), 
			Query(v -> r, mid + 1, R, mid + 1, QR),
		       	min(v -> l -> suff, mid - QL + 1) + min(v -> r -> pref, QR - mid)});
}

Node* sg[MAXN];
int n;
vector<pll> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	sg[0] = Build(1, n);

	for (int i = 1; i <= n; i++) {
		int h;
		cin >> h;
		v.push_back({h, i});
	}

	sort(all(v), greater<pll>());
	for (int i = 1; i <= n; i++) sg[i] = Update(sg[i - 1], 1, n, v[i - 1].Y);
	
	int q;
	cin >> q;
	while (q--) {
		int L, R, w, BL = 0, BR = n;
		cin >> L >> R >> w;
		
		while (BL < BR) {
			int mid = (BL + BR) >> 1;
			if (Query(sg[mid], 1, n, L, R) >= w) BR = mid;
			else BL = mid + 1;
		}
		
		cout << v[BL - 1].X << endl;
	}
	return 0;
}