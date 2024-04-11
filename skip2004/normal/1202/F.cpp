#include<bits/stdc++.h>
int a, b;
int main() {
	std::cin >> a >> b;
	const int sum = a + b;
	int ans = 0;
	for(int L = 1, R;L <= sum;) {
		R = sum / (sum / L);
		const int cnt = sum / L;
		const int ra = a / cnt, la = (a + cnt) / (cnt + 1);
		const int rb = b / cnt, lb = (b + cnt) / (cnt + 1);
		if(la <= ra && lb <= rb)
		ans += std::max(0, std::min(ra + rb, R) - std::max(L, la + lb) + 1);
		L = R + 1;
	}
	std::cout << ans << '\n';
}