#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int N, k;
ll s, c;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		ll b; scanf("%lld", &b);
		if (b%2 == 1) {
			if (c == 0 || b < c) c = b;
			k++;
		}
		s += b;
	}
	if (k % 2 == 1) s -= c;
	printf("%lld\n", s);
}