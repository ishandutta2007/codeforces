// Um_nlk :)))))
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

const ll MAXN = 1e6 + 10;

int S[MAXN], sz[MAXN];
pll P[MAXN];
vector<int> in_v[MAXN];
set<int> st;
int n;

inline void Reset(int v) {
	for (int u : in_v[v]) {
		if (P[u].X == P[u].Y) {
			if (sz[P[u].X] <= 7) st.insert(u);
			else st.erase(u);
		} else {
			int x = P[u].X, y = P[u].Y;
			if (sz[x] < 9 && sz[y] < 9) st.insert(u);
			else st.erase(u);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= 4 * n; i++) {
		int v, u1, u2;
		cin >> v >> u1 >> u2;
		S[i] = v;
		P[i] = {u1, u2};
		sz[v]++;
		in_v[u1].push_back(i);
		in_v[u2].push_back(i);
		st.insert(i);
	}

	cout << "YES" << endl;
	while (!st.empty()) {
		int t = *st.begin();
		st.erase(st.begin());
		cout << t << sep;
		sz[S[t]]--;
		sz[P[t].X]++;
		sz[P[t].Y]++;
		in_v[P[t].X].erase(find(all(in_v[P[t].X]), t));	
		in_v[P[t].Y].erase(find(all(in_v[P[t].Y]), t));	

		Reset(S[t]);
		Reset(P[t].X);
		Reset(P[t].Y);
	}

	cout << endl;
	return 0;
}