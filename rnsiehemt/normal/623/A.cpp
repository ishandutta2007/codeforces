#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 505;

int N, M, d[MaxN];
bool e[MaxN][MaxN], seen[MaxN];
char s[MaxN];

void go(int i, int k) {
	seen[i] = true;
	s[i] = 'a' + k;
	for (int j = 0; j < N; j++) if (j != i && e[i][j]) {
		if (seen[j]) {
			if (s[j] != 'a' + (2-k)) {
				printf("No\n");
				exit(0);
			}
		} else {
			go(j, 2-k);
		}
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) e[i][j] = true;
	for (int i = 0; i < M; i++) {
		int u, v; scanf("%d%d", &u, &v); u--; v--;
		e[u][v] = e[v][u] = false;
	}
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (j != i && e[i][j]) d[i]++;
	for (int i = 0; i < N; i++) if (!seen[i] && d[i]) go(i, 0);
	for (int i = 0; i < N; i++) if (!seen[i]) s[i] = 'b';
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (j != i && !e[i][j] && std::abs(s[i] - s[j]) > 1) {
		printf("No\n");
		return 0;
	}
	s[N] = '\0';
	printf("Yes\n%s\n", s);
}