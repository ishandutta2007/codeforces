#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

inline int Query(int L, int R) {
	if (L == R) return -1;
	cout << "? " << L << sep << R << endl;
       	int ans;
	cin >> ans;
	return ans;	
}  

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int ind = Query(1, n);

	if (Query(ind, n) == ind) {
		int L = ind + 1, R = n;
		while (L < R) {
			int mid = (L + R) >> 1;
			if (Query(ind, mid) == ind) R = mid;
			else L = mid + 1;
		}

		return cout << "! " << L << endl, 0;
	} else {
		int L = 1, R = ind - 1;
		while (L < R) {
			int mid = (L + R + 1) >> 1;
			if (Query(mid, ind) == ind) L = mid;
			else R = mid - 1;
		}

		return cout << "! " << L << endl, 0;
	}
	return 0;
}