// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 5000 + 10;

int n;
vector<pair<int, pll>> H, V;
bitset<MAXN> adj[MAXN];

inline bool F(int a, int b, int c) {
	if (a > c) swap(a, c);
	return a <= b && b <= c;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2) H.push_back({x1, {y1, y2}});
		else V.push_back({y1, {x1, x2}});
	}

	if (V.size() < H.size()) swap(V, H);
	ll ans = 0;
	for (int i = 0; i < H.size(); i++) {
		for (int j = 0; j < V.size(); j++) {
			if (F(H[i].Y.X, V[j].X, H[i].Y.Y) && F(V[j].Y.X, H[i].X, V[j].Y.Y)) 
				adj[i].set(j);
		}
	
		for (int j = 0; j < i; j++) {
			ll c = (adj[i] & adj[j]).count();
			ans += c * (c - 1) / 2;
		}
	}

	cout << ans << endl;
	return 0;
}