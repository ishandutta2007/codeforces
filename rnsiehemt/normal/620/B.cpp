#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define em emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int a, b, ans, g[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int f(int i) {
	if (i < 10) return g[i];
	else {
		int c = 0;
		while (i) {
			c += f(i%10);
			i /= 10;
		}
		return c;
	}
}

int main()
{
	scanf("%d%d", &a, &b);
	for (int i = a; i <= b; i++) ans += f(i);
	printf("%d\n", ans);
}