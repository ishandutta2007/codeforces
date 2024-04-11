// Sohsoh84 :)))
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
const ll SQ = 350;

int n, mx[MAXN], P[MAXN];
vector<int> st[SQ];

inline void F(int ind, int c) {
	int i = st[ind].size() - 1;
	while (i > 0 && st[ind][i] > st[ind][i - 1] && c)
		swap(st[ind][i], st[ind][i - 1]), i--, c--;
}

inline void add(int a, int c) {
	int ind = SQ - 1;
	while (true) {
		if (ind == 0) {
			st[0].push_back(a);
			mx[0] = max(mx[0], a);
			F(0, c);
			break;	
		}

		if (st[ind].size() <= c && mx[ind] < a) {
			c -= st[ind].size();
			ind--;
		} else {
			st[ind].push_back(a);
			mx[ind] = max(mx[ind], a);
			F(ind, c);
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, c;
		cin >> a >> c;
		P[a] = i;
		add(a, c);

		if (i % SQ == 0) {
			vector<int> v;
			for (int i = 0; i < SQ; i++) {
				for (int e : st[i])
					v.push_back(e);
				st[i].clear();
				mx[i] = 0;
			}
			
			for (int i = 0; i < v.size(); i++) {
				st[i / SQ].push_back(v[i]);
				mx[i / SQ] = max(mx[i / SQ], v[i]);
			}
		}
	}

	for (int i = 0; i < SQ; i++)
		for (int e : st[i])
			cout << P[e] << sep;
	cout << endl;
	return 0;
}