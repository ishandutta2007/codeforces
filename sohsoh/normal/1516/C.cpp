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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bitset<MAXN> knapsack;
int n, A[MAXN], s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	int t = (1 << 22);
	knapsack[0] = true;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		t = __gcd(t, A[i]);
		knapsack = knapsack | (knapsack << A[i]);
		s += A[i];
	}

	if (s % 2 == 1 || !knapsack[s / 2]) return cout << 0 << endl, 0;
	cout << 1 << endl;
	for (int i = 1; i <= n; i++)
		if ((A[i] / t) % 2 == 1)
			return cout << i << endl, 0;
	return 0;
}