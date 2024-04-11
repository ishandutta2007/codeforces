#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e12;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int A[MAXN], n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	ll L = *max_element(A, A + MAXN), R = INF;
	while (L < R) {
		ll mid = (L + R) / 2;
		ll sup = 0;
		for (int i = 0; i < n; i++) sup += mid - A[i];
		if (sup >= mid) R = mid;
		else L = mid + 1;
	}

	cout << L << endl;
	return 0;
}