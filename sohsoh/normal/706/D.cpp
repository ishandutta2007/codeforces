#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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
const int LOG = 30;

struct Node {
	public:
		Node() {}
		Node  *l_node = nullptr, *r_node = nullptr, *par = nullptr;	
		Node(Node* p) { par = p; }
		
		Node* L() {
			if (l_node == nullptr) l_node = new Node(this);
			return l_node;
		}

		Node* R() {
			if (r_node == nullptr) r_node = new Node(this);
			return r_node;
		}
};

Node* tree = new Node();
map<int, int> mp;

inline void Add(int x) {
	Node* v = tree;
	for (int i = LOG; i >= 0; i--) {
		if (x & (1ll << i)) v = v -> R();
		else v = v -> L();
	}
}

inline void Remove(int x) {
	Node* v = tree;
	for (int i = LOG; i >= 0; i--) {
		if (x & (1ll << i)) v = v -> R();
		else v = v -> L();
	}
	
	while (v -> par != nullptr) {
		Node* p = v -> par;
		if (v == p -> l_node) p -> l_node = nullptr;
		else if (v == p -> r_node) p -> r_node = nullptr;
		v = p;
		if (v -> l_node != nullptr || v -> r_node != nullptr) break;
	}
}

inline ll query(int x) {
	Node* v = tree;
	ll ans = 0;
	for (int i = LOG; i >= 0; i--) {
		if ((x & (1ll << i)) == 0) {
			if (v -> r_node != nullptr) ans ^= (1ll << i), v = v -> r_node;
			else v = v -> l_node;	
		} else {
			if (v -> l_node != nullptr) ans ^= (1ll << i), v = v -> l_node;
			else v = v -> r_node;		
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int q;
	cin >> q;
	Add(0);
	while (q--) {
		char c;
		int x;
		cin >> c >> x;
		if (c == '+') {
			if (mp[x] == 0) Add(x);
			mp[x]++;
		} else if (c == '-') {
			mp[x]--;
			if (mp[x] == 0) Remove(x);
		} else {
			cout << query(x) << endl;
		}
	}
	return 0;
}