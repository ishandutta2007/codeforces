#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

int N;
ll c[3000], d[3000], ans;

ll f(ll a) {
	return a*(a-1)/2;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x, y; scanf("%d%d", &x, &y);
		c[x+y]++;
		d[x-y+1005]++;
	}
	for (int i = 0; i < 3000; i++) {
		ans += f(c[i]);
		ans += f(d[i]);
	}
	printf("%lld\n", ans);
}