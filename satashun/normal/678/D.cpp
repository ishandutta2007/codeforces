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

const ll MOD = 1000000007;

ll A, B, n;
ll x;
ll r1 = 1, r2;

int main() {
    cin >> A >> B >> n >> x;

    while (n > 0) {
	if (n & 1) {
	    ll r3 = r1 * A % MOD;
	    ll r4 = (A * r2 + B) % MOD;
	    r1 = r3; r2 = r4;
	}

	ll C = A * A % MOD;
	ll D = (A * B + B) % MOD;
	A = C; B = D;

	n /= 2;
    }

    cout << (r1 * x + r2) % MOD << endl;

    return 0;
}