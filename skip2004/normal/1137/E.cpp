#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
const int mod = 998244353;
typedef std::pair<int, ll> pr;
typedef std::set<pr> set;
int n, m;
ll add_tag, mul_tag;
std::vector<pr> vc;
inline ll getv(pr x) { return x.first * mul_tag + x.second + add_tag; }
inline long double getk(pr x,pr y) { return (long double)(getv(y)-getv(x))/(y.first-x.first); }
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	vc.emplace_back(0, 0);
	int first = 0, last = n - 1;
	for(int i = 0;i < m;++i) {
		int opt, k;
		cin >> opt;
		if(opt == 1) {
			mul_tag = add_tag = 0;
			cin >> k;
			vc = {pr(first -= k, 0)};
		}
		if(opt == 2) {
			cin >> k;
			last += 1;
			pr x(last, - add_tag - (ll) last * mul_tag);
			for(;vc.size() > 1 && getk(vc.back(), x) <= getk(vc[vc.size() - 2], vc.back());) vc.pop_back();
			vc.emplace_back(x);
			last += k - 1;
		}
		if(opt == 3) {
			ll b, s;
			cin >> b >> s;
			b -= s * first;
			add_tag += b;
			mul_tag += s;
		}
		for(;vc.size() > 1 && getv(vc[vc.size() - 2]) <= getv(vc.back());) vc.pop_back();
		cout << vc.rbegin() -> first - first + 1 << ' ' << getv(vc.back()) << '\n';
	}
}