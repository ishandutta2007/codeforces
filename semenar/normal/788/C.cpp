#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(X) X.begin(), X.end()
#define sz(X) ((int)X.size())
#define fst first
#define snd second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef vector<pll> vpll;
typedef vector<ld> vld;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vbb;

const int INT_INF = 2e9;

bool is_prime(int n) {
	for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	set<int> a;
	for (int i = 0; i < k; i++) {
		int tmp;
		cin >> tmp;
		a.insert(tmp);
	}

	vi cola;
	for (auto c : a) cola.pb(c - n);

	if (cola[0] > 0 || cola.back() < 0) {
		cout << -1 << endl;
	}
	else {
		vb cola_bp(2001);
		int tries = 0;
		cola_bp[1000] = true;
		while (tries == 0 || !cola_bp[1000]) {
			vb new_coke(2001);
			for (auto c : cola) {
				int l = max(0, -c), r = 2000 - max(0, c);
				for (int i = l; i <= r; i++) {
					new_coke[i + c] = new_coke[i + c] | cola_bp[i];
				}
			}
			swap(cola_bp, new_coke);
			tries++;
		}
		cout << tries << endl;
	}
}