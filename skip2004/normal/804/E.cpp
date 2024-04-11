#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
typedef std::pair<int, int> pr;
std::vector<pr> vc;
int n;
inline void push(int a, int b) {
	if(n % 2 && (a + 1) / 2 == (b + 1) / 2) {
		vc.emplace_back(a, n);
		vc.emplace_back(a, b);
		vc.emplace_back(b, n);
	} else {
		vc.emplace_back(a, b);
	}
}
inline void make(int a) {
	push(a + 0, a + 1);
	push(a + 1, a + 2);
	push(a + 0, a + 3);
	push(a + 1, a + 3);
	push(a + 0, a + 2);
	push(a + 2, a + 3);
}
inline void make(int a, int b) {
	push(a + 0, b + 3);
	push(a + 2, b + 1);
	push(a + 2, b + 2);
	push(a + 0, b + 1);
	push(a + 1, b + 3);
	push(a + 3, b + 0);
	push(a + 2, b + 3);
	push(a + 1, b + 2);
	push(a + 3, b + 1);
	push(a + 3, b + 3);
	push(a + 0, b + 0);
	push(a + 0, b + 2);
	push(a + 2, b + 0);
	push(a + 3, b + 2);
	push(a + 1, b + 1);
	push(a + 1, b + 0);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	/*
	std::mt19937 rd(time(0));
	do {
		pr a[] = {
			pr(1, 5), pr(1, 6), pr(1, 7), pr(1, 8),
			pr(2, 5), pr(2, 6), pr(2, 7), pr(2, 8),
			pr(3, 5), pr(3, 6), pr(3, 7), pr(3, 8),
			pr(4, 5), pr(4, 6), pr(4, 7), pr(4, 8),
		};
		int p[10];
		rep(i, 1, 8) p[i] = i;
		std::shuffle(a, a + 16, rd);
		for(pr i : a) {
			std::swap(p[i.first], p[i.second]);
		}
		int ok = 1;
		rep(i, 1, 8) {
			ok = ok && p[i] == i;
		}
		if(ok) {
			for(pr i : a) {
				cout << "push(a + " << i.first - 1 << ", b + " << i.second - 5 << ");\n";
			}
			break;
		}
	} while(1);
	*/
	cin >> n;
	if(n % 4 == 2 || n % 4 == 3) {
		cout << "NO" << '\n';
		return 0;
	} else {
		cout << "YES" << '\n';
		for(int i = 1;i + 3 <= n;i += 4) make(i);
		for(int i = 1;i + 3 <= n;i += 4) for(int j = i + 4;j + 3 <= n;j += 4) make(i, j);
		for(pr i : vc) {
			if(i.first > i.second) {
				std::swap(i.first, i.second);
			}
			cout << i.first << ' ' << i.second << '\n';
		}
	}
}