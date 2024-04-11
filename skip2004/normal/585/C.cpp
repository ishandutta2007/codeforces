#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
inline std::string make(ll a, ll b) {
	if(!a && !b) return "";
	if(a == b) return "fail";
	// opt A : (a, b) => (a - 1 - b, b)
	// opt B : (a, b) => (a, b - 1 - a)
	if(a > b) {
		return std::to_string(a / (b + 1)) + "A" + make(a % (1 + b), b);
	} else {
		return std::to_string(b / (a + 1)) + "B" + make(a, b % (1 + a));
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	ll a, b;
	cin >> a >> b;
	auto res = make(a - 1, b - 1);
	if(res.size() && res.back() == 'l') {
		cout << "Impossible" << '\n';
	} else {
		cout << res << '\n';
	}
}