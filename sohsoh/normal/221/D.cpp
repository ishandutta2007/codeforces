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

const ll MAXN = 1e5 + 10;
const ll SQ = 617;

map<int, int> cnt;
int n, q, A[MAXN], ps[MAXN], ans[MAXN];
vector<int> v;
vector<pll> Q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		cnt[A[i]]++;
	}

	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		Q.push_back({l, r});
	}

	for (pll e : cnt) {
		if (e.Y >= e.X) {
			for (int i = 1; i <= n; i++)
				ps[i] = ps[i - 1] + (A[i] == e.X);
			for (int i = 0; i < q; i++)
				ans[i] += (ps[Q[i].Y] - ps[Q[i].X - 1] == e.X);
		}
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] << endl;
	return 0;
}