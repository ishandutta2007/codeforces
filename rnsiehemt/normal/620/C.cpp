#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define em emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 300005;

int N, a[MaxN], c[MaxN], t[MaxN], gt;
std::vector<int> alla;
std::vector<std::pair<int, int>> r;

bool add(int i) {
	if (gt > t[i]) {
		t[i] = gt;
		c[i] = 0;
	}
	c[i]++;
	return c[i] > 1;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		alla.pb(a[i]);
	}
	std::sort(all(alla));
	alla.erase(std::unique(all(alla)), alla.end());
	int start = 0;
	for (int i = 0; i < N; i++) {
		a[i] = std::lower_bound(all(alla), a[i]) - alla.begin();
		if (add(a[i])) {
			r.pb({start, i});
			gt++;
			start = i+1;
		}
	}
	//for (int i = 0; i < N; i++) printf("%d%c", a[i], " \n"[i == N-1]);
	if (r.empty()) printf("-1\n");
	else {
		r.back().second = N-1;
		printf("%d\n", sz(r));
		for (auto &p : r) printf("%d %d\n", p.first + 1, p.second + 1);
	}
}