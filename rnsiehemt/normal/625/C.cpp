#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 505;

int N, K, g[MaxN][MaxN], ans;

int main()
{
	scanf("%d%d", &N, &K);
	int k = N*N;
	for (int y = 0; y < N; y++) {
		for (int x = N-1; x >= K-1; x--) {
			g[y][x] = k--;
			if (x == K-1) ans += g[y][x];
		}
	}
	k = 1;
	for (int y = N-1; y >= 0; y--) {
		for (int x = 0; x < K-1; x++) {
			g[y][x] = k++;
		}
	}
	printf("%d\n", ans);
	for (int y = 0; y < N; y++) for (int x = 0; x < N; x++) printf("%d%c", g[y][x], " \n"[x == N-1]);
}