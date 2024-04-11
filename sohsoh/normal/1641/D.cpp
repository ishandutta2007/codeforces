#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e5 + 10;
const ll SQ = 100;

bitset<MAXN> st[5 * MAXN / SQ];
vector<int> vec[MAXN * 5], V;
int n, m, c0, c1, T[MAXN][5], ind[MAXN * 5], P[MAXN * 5];
vector<pll> w;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> T[i][j];
			V.push_back(T[i][j]);
		}

		

		int x;
		cin >> x;
		w.push_back({x, i});	
	}

	sort(all(w));
	for (int i = 0; i < n; i++)
		ind[w[i].Y] = i;

	sort(all(V));
	V.resize(unique(all(V)) - V.begin());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			T[i][j] = lower_bound(all(V), T[i][j]) - V.begin() + 1;
			vec[T[i][j]].push_back(ind[i]);
		}
	}

	int cnt = 0;
	for (int i = 0; i < n * m + 10; i++) {
		if (vec[i].size() > SQ) {
			P[i] = ++cnt;
			for (int e : vec[i])
				st[cnt].set(e);
		}
	}

	int ans = -1;
	for (int i = 0; i < n; i++) {
		bitset<MAXN> tmp;
		int fuck = w[i].Y;

		for (int j = 0; j < m; j++) {
			int x = T[fuck][j];
			
			if (vec[x].size() > SQ) tmp |= st[P[x]];
			else {
				for (int e : vec[x]) {
					tmp.set(e);
				}
			}
		}

		tmp.flip();
		int j = tmp._Find_first();
		if (j >= n) continue;
		int s = w[i].X + w[j].X;
		
		if (ans == -1) ans = s;
		else ans = min(ans, s);
	}

	cout << ans << endl;
	return 0;
}