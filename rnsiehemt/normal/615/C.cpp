#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int S, T, N = 1, c[2105*2105][26], best[2105], prev[2105];
std::pair<int, int> r[2105*2105], bestr[2105];
std::vector<std::pair<int, int>> v;
char s[2105], t[2105];

void check(int &a) {
	if (!a) a = N++;
}

int main()
{
	scanf(" %s %s", s, t);
	S = strlen(s); T = strlen(t);
	for (int i = 0; i < S; i++) {
		int n = 0;
		for (int j = i; j < S; j++) {
			int a = s[j] - 'a';
			if (!c[n][a]) {
				c[n][a] = N++;
				r[c[n][a]] = {i, j};
			}
			n = c[n][a];
		}
		n = 0;
		for (int j = i; j >= 0; j--) {
			int a = s[j] - 'a';
			if (!c[n][a]) {
				c[n][a] = N++;
				r[c[n][a]] = {i, j};
			}
			n = c[n][a];
		}
	}
	std::fill(best, best+T+1, 1e9);
	best[0] = 0;
	for (int i = 0; i < T; i++) {
		int n = 0;
		for (int j = i; j < T; j++) {
			int a = t[j] - 'a';
			if (!c[n][a]) break;
			n = c[n][a];
			if (domin(best[j+1], best[i] + 1)) {
				bestr[j+1] = r[n];
				prev[j+1] = i;
			}
		}
	}
	if (best[T] == 1e9) {
		printf("-1\n");
	} else {
		int n = T;
		while (n) {
			v.pb(bestr[n]);
			n = prev[n];
		}
		std::reverse(all(v));
		printf("%d\n", sz(v));
		for (auto &p : v) printf("%d %d\n", p.first+1, p.second+1);
	}
}