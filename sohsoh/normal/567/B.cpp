#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int fans = 0, ans = 0;
bool B[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	while (n--) {
		char c;
		int x;
		cin >> c >> x;
		if (c == '+') {
			B[x] = true;
			ans++;
		} else if (B[x]) {
			B[x] = false;
			ans--;
		} else fans++;

		fans = max(fans, ans);
	}

	cout << fans << endl;
	return 0;
}