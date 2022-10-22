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

ll lb(ll x)
{
    ll lo = 1, hi = 100000;

    while (hi - lo > 1) {
	ll m = (lo + hi) / 2;
	if (m * (m - 1) / 2 <= x) lo = m;
	else hi = m;
    }
    return lo;
}

ll a, b, c, d;
ll p, q;
string ans;

int main() {
    cin >> a >> b >> c >> d;

    p = lb(a);
    q = lb(d);

    if (p * (p - 1) / 2 != a || q * (q - 1) / 2 != d) {
	puts("Impossible");
	return 0;
    }

    if (b == 0 && c == 0 && d == 0) {
	rep(i, p) ans.pb('0');
	cout << ans << endl;
	return 0;
    }

    if (a == 0 && b == 0 && c == 0) {
	rep(i, q) ans.pb('1');
	cout << ans << endl;
	return 0;
    }

    if (b + c != p * q) {
	puts("Impossible");
	return 0;	
    }

    rep(i, p + q) ans.pb('1');

    ll num = a + c;
    ll s = a;

    if (num < s) {
	puts("Impossible");
	return 0;	
    }

    int i = p - 1;

    while (i >= 0) {
	ll mv = min(q, num - s);
	s += mv;

	ans[i + mv] = '0';

	--i;
    }

    if (num == s) {
	cout << ans << endl;
    } else puts("Impossible");

    return 0;
}