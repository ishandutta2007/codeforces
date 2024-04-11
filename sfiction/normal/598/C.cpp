#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PLL;

const int MAXN = 1E5 + 10;

ll sqr(ll x){
	return x * x;
}

struct VEC{
	int x, y;
	int id;

	int loc()const{
		return y < 0 || y == 0 && x < 0;
	}
}a[MAXN];

bool operator<(const VEC &l, const VEC &r){
	return l.loc() != r.loc() ? l.loc() < r.loc() : l.x * r.y > l.y * r.x;
}

PLL product(ll x, ll y){
	static ll k = 2E8;
	ll x1 = x / k, x0 = x % k, y1 = y / k, y0 = y % k;
	return PLL(x1 * y1 + (x1 * y0 + x0 * y1) / k, (x1 * y0 + x0 * y1) % k * k + x0 * y0);
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].id = i + 1;
	}
	sort(a, a + n);

	a[n] = a[0];
	ll a1, b1;
	int ans;
	for (int i = 0; i < n; ++i){
		ll a2 = a[i].x * a[i + 1].x + a[i].y * a[i + 1].y, b2 = (sqr(a[i].x) + sqr(a[i].y)) * (sqr(a[i + 1].x) + sqr(a[i + 1].y));
		a2 *= a2 >= 0 ? a2 : -a2;
		if (!i || product(a2, b1) > product(a1, b2)){
			a1 = a2;
			b1 = b2;
			ans = i;
		}
	}
	printf("%d %d\n", a[ans].id, a[ans + 1].id);
	return 0;
}