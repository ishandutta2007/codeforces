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

int n, t[MAXN];
map<int, queue<int>> mp;

void modify(int p, int value) {
	for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
}

int query(int l, int r) { 
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = max(res, t[l++]);
		if (r&1) res = max(res, t[--r]);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	n = q + 10;
	int ptr1 = 0, ptr2 = 0;
	while (q--) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int m;
			cin >> m;
			modify(ptr1, m);
			mp[m].push(ptr1);
			ptr1++;
		} else if (cmd == 2) {
			while (query(ptr2, ptr2 + 1) <= 0) ptr2++;
		       	cout << ptr2 + 1 << sep;
			mp[query(ptr2, ptr2 + 1)].pop();	
			modify(ptr2, -1);
		} else {
			int ans_t = query(0, n + 1);
			int ind = mp[ans_t].front();
			mp[ans_t].pop();
			cout << ind + 1 << sep;
			modify(ind, -1);
		}
	}

	cout << endl;
	return 0;
}