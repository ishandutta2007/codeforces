/*
    Soheil Mohammadkhani
    IDK :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9


ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

ll n, A[MAXN], cnt[MAXN] = {0}, dp[MAXN] = {0};

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i], cnt[A[i]]++;
	ll x = *max_element(A, A + n);
	dp[x] = count(A, A + n, x) * x;
	while (x--) {
		dp[x] = max(dp[x + 1], dp[x + 2] + cnt[x] * x);
	}

	cout << dp[0] << endl;
}