#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

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
typedef string str;

typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef vector<pll> vpll;
typedef vector<ld> vld;
typedef vector<string> vs;
typedef vector<bool> vb;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cout << fixed << setprecision(12);

	int n, b;
	cin >> n >> b;

	vi a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	ld avg = b;
	for (int i = 0; i < n; i++) avg += a[i];
	for (int i = 0; i < n; i++) {
		if (a[i] * n > avg) {
			cout << -1 << endl;
			return 0;
		}
	}

	avg /= n;

	for (int i = 0; i < n; i++) {
		cout << avg - a[i] << endl;
	}
}