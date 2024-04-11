#include<bits/stdc++.h>

using std::cin;
using std::cout;

int q, a, b;

char s[1 << 20];

bool solve() {
	cin >> a >> b >> s;
	int len = strlen(s);
	std::vector<int> vec;
	int cnt = 0;
	for(int i = 0;i < len;++i) {
		if(s[i] == '.') {
			++ cnt;
		} else {
			if(cnt >= b)
				vec.push_back(cnt);
			cnt = 0;
		}
	}
	if(cnt >= b) {
		vec.push_back(cnt);
	}
	int b_can = 0, T = 0;
	for(int i : vec) {
		if(i < a) return 0;
		if(i >= b + b) {
			++ b_can;
			T = i;
		}
	}
	if(b_can == 0) return vec.size() % 2;
	if(b_can >= 2) return 0;
	for(int i = 1;i + a - 1 <= T;++i) {
		int left = i - 1, right = T - (i + a - 1);
		if(left >= b + b || right >= b + b || b <= left && left < a || b <= right && right < a) continue;
		if(vec.size() + (a <= left && left < b + b) + (a <= right && right < b + b) & 1)
			return 1;
	}
	return 0;

}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> q;
	for(;q--;) {
		cout << (solve() ? "YES" : "NO") << '\n';
	}
}