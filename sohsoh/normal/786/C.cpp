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

struct Node {
	Node *L, *R;
	int val, ind;

	Node(int val): L(nullptr), R(nullptr), val(val) {}
	Node(int val, int ind): L(nullptr), R(nullptr), val(val), ind(ind) {}
	Node(Node* L, Node* R): L(L), R(R), val(0) {
		if (L) val += L -> val;
		if (R) val += R -> val;
	}
};

Node* Build(int L, int R) {
	if (L == R) return new Node(0, L);
	int mid = (L + R) >> 1;
	return new Node(Build(L, mid), Build(mid + 1, R));
}

int Query(Node* v, int L, int R, int val) {
	if (L == R) return v -> ind;
	int mid = (L + R) >> 1;
	if (val <= v -> L -> val) return Query(v -> L, L, mid, val);
	else return Query(v -> R, mid + 1, R, val - v -> L -> val);
}

Node* Update(Node* v, int L, int R, int ind, int val) {
	if (L == R) return new Node(val, L);
	int mid = (L + R) >> 1;
	if (ind <= mid) return new Node(Update(v -> L, L, mid, ind, val), v -> R);
	else return new Node(v -> L, Update(v -> R, mid + 1, R, ind, val));
}

Node* sg[MAXN];
int n, A[MAXN], lst[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];

	sg[n + 1] = Build(1, n + 1);
	for (int i = n; i > 0; i--) {
		sg[i] = Update(sg[i + 1], 1, n + 1, i, 1);
		if (lst[A[i]]) sg[i] = Update(sg[i], 1, n + 1, lst[A[i]], 0);
		lst[A[i]] = i;
	}

	for (int i = 1; i <= n; i++) {
		int ind = 1, ans = 0;
		while (ind <= n) {
			ans++;
			ind = Query(sg[ind], 1, n + 1, i + 1);
		}

		cout << ans << sep;
	}
	
	cout << endl;
	return 0;
}