// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 4e6 + 10;

ll n, MOD, ps[MAXN], ps2[MAXN], f[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> MOD;
	f[n] = ps[n] = ps2[n] = 1;

	for (int i = n - 1; i >= 1; i--) {
		for (int j = 2 * i; j < MAXN; j += i) 
			f[i] += ps[j];
		f[i] += ps2[i + 2] + 1;	
		f[i] %= MOD;
		ps[i] = (ps[i + 1] + f[i]) % MOD;
		ps2[i] = (ps2[i + 1] + ps[i]) % MOD;
	}
	
	cout << f[1] << endl;
	return 0;
}