#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

vector<int> v;

bool lucky(int k) {
	while (k) {
		int d = k % 10;
		k /= 10;
		if (d != 4 && d != 7) return false;
	}
	return true;
}

int N, K;
int main() {
	scanf("%d %d", &N, &K);
	--K;

	ll fac = 1;
	int cur = 0;
	while (fac <= K) {
		++cur;
		fac *= cur;
	}
	if (cur > N) {
		printf("-1\n");
		return 0;
	}

	int ans = 0;
	if (4 <= N - cur) ++ans;
	if (7 <= N - cur) ++ans;
	for(int i = 0; i < 10000000; ++i) {
		int a = i * 100 + 44;
		int b = i * 100 + 47;
		int c = i * 100 + 74;
		int d = i * 100 + 77;
		if (a <= N - cur && lucky(a)) ++ans;
		if (b <= N - cur && lucky(b)) ++ans;
		if (c <= N - cur && lucky(c)) ++ans;
		if (d <= N - cur && lucky(d)) ++ans;
	}

	for(int i = N - cur + 1; i <= N; ++i) {
		v.push_back(i);
	}

	for(int i = N - cur + 1; i <= N; ++i) {
		fac /= cur;
		--cur;

		int num = K / fac;
		K -= num * fac;
		int nxt = v[num];
		v.erase(v.begin() + num);
		if (lucky(i) && lucky(nxt)) ++ans;
	}

	printf("%d\n", ans);
	return 0;
}