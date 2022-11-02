#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define em emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int main()
{
	int Y, X, ans = -1e9; scanf("%d%d", &Y, &X);
	for (int y = 0; y < Y; y++) {
		int min = 2e9;
		for (int x = 0; x < X; x++) {
			int a; scanf("%d", &a);
			domin(min, a);
		}
		domax(ans, min);
	}
	printf("%d\n", ans);
}