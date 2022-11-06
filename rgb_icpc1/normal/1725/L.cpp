#include<bits/stdc++.h>
using namespace std;

#define sz(x) (int((x).size()))
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define F1(x) function<void(int)> x = [&] 
#define F2(x) function<void(int, int)> x = [&] 
#define F3(x) function<void(int, int, int)> x = [&]
 
template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
using LL = long long;
using PI = pair<int, int>;
using VI = vector<int>;
using VPI = vector<PI>;
const int N = 1000005;
const LL oo = 1000000000000000005LL;
const int P1 = 998244353;
const int P2 = 1000000007;
const int P = P1;

//assume -1 < x, y < P
inline int add(int x, int y) {
	return (x + y) % P;
}

inline int mul(int x, int y) {
	return 1LL * x * y % P;
}

inline int sub(int x, int y) {
	return (x + P - y) % P;
}

string itos(int x) {
	string str = "";
	while (x) {
		str += (x % 10 + '0');
		x /= 10;
	}
	reverse(str.begin(), str.end());
	return str;
}

struct BIT {
	LL v[N];
	int n, pw;
	
	void init(int m) {
		n = m;
		fill_n(v, n + 1, 0);
		for (pw = 1; pw * 2 <= n; pw *= 2);
	}
	
	void add(int k, LL d) {
		for (; k <= n; k += k & -k) v[k] += d;
	}
	
	LL get(int k) {
		LL s = 0;
		for (; k > 0; k -= k & -k) s += v[k];
		return s;
	}
}BT;

int a[N];
LL b[N];
int id[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	bool f = 0;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		if (i) b[i] = b[i - 1];
		b[i] += a[i];
		if (b[i] < 0) f = 1;
		id[i] = i;
	}
	for (int i = 0; i < n - 1; i ++) if (b[i] > b[n - 1]) f = 1;
	if (f) {
		cout << -1 << endl;
		return 0;
	}
	sort(id, id + n, [](int x, int y) {
		if (b[x] == b[y]) return x < y;
		return b[x] < b[y];
	});
	LL rlt = 0;
	BT.init(n);
	for (int i = 0; i < n; i ++) {
		rlt += BT.get(n) - BT.get(id[i] + 1);
		BT.add(id[i] + 1, 1);
	}
	cout << rlt << endl;
	return 0;
}