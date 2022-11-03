#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N, K;
vector<int> ans;

int main() {
	scanf("%d%d", &N, &K);
	int d = (N + K - 1) / K;
	for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j) {
		int ni = i, nj = j, ts = 0, nt = 0;
		while (ni || nj) {
			if (ni % K != nj % K) nt = ts;
			++ts;
			ni /= K; nj /= K;
		}
		ans.push_back(nt + 1);
	}
	printf("%d\n", *max_element(ans.begin(), ans.end()));
	for (int i : ans) printf("%d ", i);
	puts("");
	return 0;
}