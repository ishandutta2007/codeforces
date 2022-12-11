#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 100010;

char a[NMAX], b[NMAX];

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", a);
	scanf("%s", b);
	int ans = 0;
	for (int i = 0; i < n - 1 - i; ++i) {
		map<char, int> orbitOcc;
		orbitOcc[a[i]]++;
		orbitOcc[b[i]]++;
		orbitOcc[a[n-1-i]]++;
		orbitOcc[b[n-1-i]]++;
		bool orbitPass = true;
		for (auto c_o : orbitOcc) if (c_o.second % 2 == 1) orbitPass = false;
		if (orbitPass) continue;
		set<char> distCount{a[i], b[i], a[n-1-i], b[n-1-i]};
		if (distCount.size() == 2) ++ans;
		else if (distCount.size() == 3) {
			if (a[i] == a[n-1-i]) ans += 2;
			else ++ans;
		} else ans += 2;
	}
	if (n % 2 == 1 && a[n/2] != b[n/2]) ++ans;
	printf("%d\n", ans);
	return 0;
}