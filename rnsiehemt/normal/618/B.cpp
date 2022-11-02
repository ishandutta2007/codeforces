#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int N, a, g[55];
bool first = true;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int max = 0;
		for (int j = 0; j < N; j++) {
			scanf("%d", &a);
			domax(max, a);
		}
		g[i] = max;
		if (g[i] == N-1 && first) {
			first = false;
			g[i]++;
		}
	}
	for (int i = 0; i < N; i++) printf("%d%c", g[i], " \n"[i==N-1]);
}