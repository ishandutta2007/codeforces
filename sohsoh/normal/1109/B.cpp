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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	if (count(all(s), s[0]) >= s.size() - 1) return cout << "Impossible" << endl, 0;
	for (int i = 1; i < s.size(); i++) {
		string s1 = s.substr(0, i);
		string s2 = s.substr(i, s.size() - i);
		string res = s2 + s1;
		string res_rev = res;
		reverse(all(res_rev));
		if (res_rev == res && res != s) return cout << 1 << endl, 0;
	}

	cout << 2 << endl;
	return 0;
}