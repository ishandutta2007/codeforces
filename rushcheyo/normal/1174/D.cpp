#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18 | 5;
int n, x, a[N];

int main() {
	scanf("%d%d", &n, &x);
	set<int> s;
	for (int i = 1; i < 1 << n; ++i)
		s.insert(i);
	s.erase(x);
	vector<int> out;
	while (!s.empty()) {
		int y = *s.begin();
		out.push_back(y);
		s.erase(y), s.erase(y ^ x);
	}
	printf("%d\n", (int)out.size());
	for (int i = (int)out.size() - 1; i >= 1; --i)
		out[i] ^= out[i - 1];
	for (int i = 0; i < (int)out.size(); ++i)
		printf("%d ", out[i]);
	return 0;
}