// orz
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e5 + 10;

ll n, k, A[MAXN];

inline ll f_and(int i, int j) {
	cout << "and" << sep << i << sep << j << endl;
	ll x;
	cin >> x;
	return x;
} 

inline ll f_or(int i, int j) {
	cout << "or" << sep << i << sep << j << endl;
	ll x;
	cin >> x;
	return x;	
}

inline ll f_xor(int i, int j) {
	return f_or(i, j) - f_and(i, j);	
}

inline ll f_sum(int i, int j) {
	ll a = f_and(i, j), o = f_or(i, j);
	return o + a;
}

int main() {
	cin >> n >> k;
	ll a = f_sum(1, 2), b = f_sum(2, 3), c = f_sum(1, 3);
	A[1] = (a + c - b) / 2;
	A[2] = (a + b - c) / 2;
	A[3] = (b + c - a) / 2;

	for (int i = 4; i <= n; i++) {
		ll x = f_xor(1, i);
		A[i] = A[1] ^ x;
	}

	sort(A + 1, A + n + 1);
	cout << "finish" << sep << A[k] << endl;
	return 0;
}