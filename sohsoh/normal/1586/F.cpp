//: // ////: ///  / : //// / :
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

const ll MAXN = 1e3 + 10;

int C[MAXN][MAXN], k, n, ans;

void f(int l, int r, int c) {
	if (r <= l) return;

	ans = max(ans, c);
	int m = (r - l + 1);
	int len = m / k, rem = m % k;

	vector<pll> v;
	while (rem) {
		f(l, l + len, c + 1);
		m -= len + 1;	
		v.push_back({l, l + len});
		l += len + 1;
		rem--;
	}

	while (l <= r) {
		f(l, l + len - 1, c + 1);
		v.push_back({l, l + len - 1});
		m -= len;
		l += len;
	}

	for (int i = 0; i < v.size(); i++)
		for (int j = i + 1; j < v.size(); j++)
			for (int a = v[i].X; a <= v[i].Y; a++)
				for (int b = v[j].X; b <= v[j].Y; b++)
					C[a][b] = c;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;

	f(1, n, 1);
	cout << ans << endl;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			cout << C[i][j] << sep;
	cout << endl;
	return 0;
}