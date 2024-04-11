#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define eb emplace_back
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int N, M;
bool p[105];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		int x; scanf("%d", &x);
		for (int j = 0; j < x; j++) {
			int y; scanf("%d", &y);
			p[y] = true;
		}
	}
	for (int i = 1; i <= M; i++) {
		if (!p[i]) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}