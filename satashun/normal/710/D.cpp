#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

// a x + b y = gcd(a, b)

ll extgcd(ll a, ll b, ll &x, ll &y)
{
    ll g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}

ll a1, b1, a2, b2, L, R;

int main() {
    cin >> a1 >> b1 >> a2 >> b2 >> L >> R;

    ll d = __gcd(a1, a2);

    if ((b2 - b1) % d != 0) {
	puts("0");
	return 0;
    }

    ll x, y;
    extgcd(a1, a2, x, y);

    y *= -1;
    x *= (b2 - b1) / d;
    y *= (b2 - b1) / d;

    ll w1 = a2 / d, w2 = a1 / d;

    if (x < 0) {
	ll up = abs(x) / w1 + 1;
	x += up * w1;
	y += up * w2;	
    }

    if (y < 0) {
	ll up = abs(y) / w2 + 1;
	x += up * w1;
	y += up * w2;
    }

    ll down = min(x / w1, y / w2);

    x -= down * w1;

    //cout << x << " " << y << endl;
    L -= a1 * x + b1;
    R -= a1 * x + b1;

    if (R < 0) {
	puts("0");
	return 0;
    }

    L = max(L, 0LL);

    ll ret = R / (w1 * a1) + 1;

    if (L > 0) {
	ret -= (L - 1) / (w1 * a1) + 1;
    }

    cout << ret << endl;

    return 0;
}