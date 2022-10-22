#include<bits/stdc++.h>
using ll = long long;
using std::cin;
using std::cout;
inline int getd(int x) {
	int d = 1;
	for(int i = 2;i * i <= x;++i) if(x % i == 0) {
		int c = 0;
		do x /= i, ++ c; while(x % i == 0);
		d *= c + 1;
	}
	if(x > 1) d <<= 1;
	return d;
}
std::mt19937 rd;
class number {
	private:
		int a;
	public :
		inline void init() {
			a = rd() % (int) 1e9 + 1;
		}
		inline int ask(ll x) {
			cout << "? " << x << std::endl;
			ll res;
			std::cin >> res;
			return res;
			return std::__gcd<ll>(x, a);
		}
		inline void output(ll x) {
			std::cout << "! " << x << std::endl;
			return ;
			int p = getd(a);
			std::cerr << "std ans is : " << p << ' ' << "your is " << x << '\n';
			if(std::abs(p - x) <= 7 || .5 <= (double) x / p && (double) x / p <= 2) {
				std::cerr << "yes ";
			} else {
				std::cerr << "no ";
				exit(0);
			}
		}
} num;
using vec = std::vector<int>;
using pr = std::pair<ll, vec>;
vec part1, part2;
std::vector<pr> ask1, ask2;

inline void init(std::vector<int> & a, std::vector<pr> & b) {
	using LL = __int128;
	LL x = 1; vec vc;
	for(auto i : a) {
		if((LL) x * i <= 1e18) x *= i, vc.push_back(i);
		else {
			b.push_back(pr(x, vc));
			x = i, vc = {i};
		}
	}
	if(x > 1) b.push_back(pr(x, vc));
}
inline ll test(ll x) {
	ll i = 1;
	for(;i * x <= 1e9;) i *= x;
	return i;
}
int main() {
	for(int i = 2;i <= pow(1e9, 1. / 4);++i) if(getd(i) == 2) part1.push_back(i);
	for(int i = pow(1e9, 1. / 4);i <= pow(1e9, 1. / 3);++i) if(getd(i) == 2) part2.push_back(i);
	init(part1, ask1);
	init(part2, ask2);
	int t;
	std::cin >> t;
	for(int i = 0;i < t;++i) {
		num.init();
		std::vector<int> d;
		for(auto a : ask1) {
			ll res = num.ask(a.first);
			if(res != 1) for(auto x : a.second) if(res % x == 0) d.push_back(x);
		}
		ll cur = 1;
		for(int i = 0;i < d.size();i += 2) {
			ll p = test(d[i]);
			if(i != d.size() - 1) p *= test(d[i + 1]);
			cur *= num.ask(p);
		}
		if(cur == 1) {
			cur = 8;
		} else {
			cur = getd(cur);
			for(auto a : ask2) {
				if(pow(a.second.front(), 3) * cur > 1e9) break;
				ll res = num.ask(a.first);
				if(res != 1) {
					cur <<= 1;
					break;
				}
			}
			cur <<= 1;
		}
		num.output(cur);
	}
}