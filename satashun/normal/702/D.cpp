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

ll d, k, a, b, t;
ll ret;

int main() {
    cin >> d >> k >> a >> b >> t;

    if (d < k) {
	ret = d * a;
    } else {
	ll t1 = k * (a - b) + b * d;

	ll num = d / k;
	ll t2 = num * (t - k * (b - a)) + b * d - t;

	ret = min(t1, t2);

	ll ds = d - num * k;
	ll t3 = ds * a + k * a * num + t * num;
	ret = min(ret, t3);
    }

    cout << ret << endl;

    return 0;
}