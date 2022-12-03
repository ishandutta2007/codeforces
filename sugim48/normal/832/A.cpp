#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;

int main() {
	ll x, y; cin >> x >> y;
	ll t = x / y;
	cout << (t % 2 ? "YES" : "NO") << endl;
}