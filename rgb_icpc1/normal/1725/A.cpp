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

int a[N], b[N];
string s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	if (m == 1) {
		cout << n - 1 << endl;
	} else cout << 1ll * (m - 1) * n << endl;
	return 0;
}