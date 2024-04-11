#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define eb emplace_back
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 100005;

int N, M;
std::vector<int> e[MaxN];
ll l[MaxN], ans;

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		e[a].eb(b);
		e[b].eb(a);
	}

	for (int i = 0; i < N; i++) {
		domax(l[i], 1ll);
		for (int j : e[i]) {
			if (j > i) domax(l[j], l[i]+1);
		}
		domax(ans, l[i] * sz(e[i]));
	}
	printf("%lld\n", ans);
}