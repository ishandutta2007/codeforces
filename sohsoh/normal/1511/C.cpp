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

int F[MAXN];
int n, q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (F[x] == 0) F[x] = i;
	}

	vector<pll> v;
	for (int i = 1; i <= 52; i++) {
		if (F[i]) {
			v.push_back({F[i], i});
		}
	}

	sort(all(v));
	while (q--) {
		int x;
		cin >> x;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].Y == x) {
				for (int j = 0; j < i; j++)
					v[j].X++;
				
				cout << v[i].X << sep;	
				v[i].X = 1;
				break;
			}
		}


		sort(all(v));
	}

	cout << endl;

	return 0;
}