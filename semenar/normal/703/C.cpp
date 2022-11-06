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
typedef vector<string> vs;
typedef vector<bool> vb;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n, w, v, u;
	cin >> n >> w >> v >> u;

	vpll pts(n);
	for (int i = 0; i < n; i++) cin >> pts[i].fst >> pts[i].snd;

	cout << fixed << setprecision(12);

	// Find block
	int roadblock = -1;
	for (int i = 0; i < n; i++) {
		// if first point is HIGHER and second point is LOWER
		int sp = (i + 1) % n;
		if (pts[i].fst * u - pts[i].snd * v < 0 && pts[sp].fst * u - pts[sp].snd * v >= 0) roadblock = i;
	}

	if (roadblock == -1) {
		cout << (ld)w / u << endl;
		return 0;
	}

	// Rotate until good
	while (true) {
		int sp = (roadblock + 1) % n;
		if (pts[roadblock].fst * u - pts[roadblock].snd * v <= pts[sp].fst * u - pts[sp].snd * v) roadblock = sp;
		else break;
	}

	cout << (ld)pts[roadblock].first / v + (ld)(w - pts[roadblock].second) / u << endl;
}