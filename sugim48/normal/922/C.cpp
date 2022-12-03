#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, int> d_i;
const int MOD = 1e9 + 7;
const int INF = INT_MAX / 2;
struct edge { int i, v, w; };

int main() {
	ll n, k; cin >> n >> k;
	set<ll> st;
	for (ll i = 1; i <= k; i++) {
		if (st.count(n % i)) {
			cout << "No" << endl;
			return 0;
		}
		st.insert(n % i);
	}
	cout << "Yes" << endl;
}