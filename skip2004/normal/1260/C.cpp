#include<bits/stdc++.h>
using std::cin;
using std::cout;
int t, p1, p2, k;

inline int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> t;
	for(int i = 0;i < t;++i) {
		cin >> p1 >> p2 >> k;
		if(p1 > p2) std::swap(p1, p2);
		int first = gcd(p1, p2);
		cout << ((p2 - first - 1) / p1 + 1 < k ? "OBEY" : "REBEL") << '\n';
	}
}