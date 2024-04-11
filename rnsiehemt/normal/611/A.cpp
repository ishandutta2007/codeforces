#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int main()
{
	int x, ans; char c;
	scanf("%d %*s %c%*s", &x, &c);
	if (c == 'w') {
		if (x == 5 || x == 6) ans = 53;
		else ans = 52;
	} else {
		if (x == 31) ans = 7;
		else if (x == 30) ans = 11;
		else ans = 12;
	}
	printf("%d\n", ans);
}