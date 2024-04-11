#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

ll ff(ll a) {
	ll le = 1, ri = 1000010;
	while (le <= ri) {
		ll mi = (le+ri)/2;
		if (mi*mi*mi > a) ri = mi-1;
		else le = mi+1;
	}
	return ri;
}

int main() {
	int _;
	scanf("%d", &_);
	while (_--) {
		int a, b;
		scanf("%d%d", &a, &b);
		ll xy = ff((ll)a*b);
		ll x = a/xy;
		ll y = b/xy;
		if (a == x*x*y && b == x*y*y) puts ("Yes");
		else puts ("No");
	}
	return 0;
}