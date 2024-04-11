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

int n, q, pref[MAXN][3], suff[MAXN][3], T[MAXN];
string s;

void update(int ind, char c, int l = 1, int r = n, int v = 1) {
	if (l == r) {
		T[v] = (c == 'b' ? 1 : 0);
		pref[v][0] = (c == 'a' ? 1 : 0);
		suff[v][0] = (c == 'c' ? 1 : 0);
		return;
	}

	int mid = (l + r) >> 1;
	if (ind <= mid) update(ind, c, l, mid, v << 1);
	else update(ind, c, mid + 1, r, v << 1 | 1);

	int a = (v << 1), b = (v << 1 | 1);
	T[v] = T[a] + T[b];
	pref[v][0] = pref[a][0] + pref[b][0];
	pref[v][1] = min(pref[a][1] + T[b], pref[a][0] + pref[b][1]);
	pref[v][2] = min({pref[a][2] + suff[b][0], pref[a][1] + suff[b][1] , pref[a][0] + pref[b][2]});
	
	swap(a, b);
	suff[v][0] = suff[a][0] + suff[b][0];
	suff[v][1] = min(suff[a][1] + T[b], suff[a][0] + suff[b][1]);
	suff[v][2] = min({suff[a][2] + suff[b][0], suff[a][1] + suff[b][1] , suff[a][0] + suff[b][2]});
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q >> s;
	s = "." + s;
	for (int i = 1; i <= n; i++) 
		update(i, s[i]);

	while (q--) {
		int i;
		char c;
		cin >> i >> c;
		update(i, c);

		cout << min({pref[1][0], pref[1][1], pref[1][2]}) << endl;
	}
	return 0;
}