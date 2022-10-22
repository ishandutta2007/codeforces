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

int n, k, T[MAXN], A[MAXN];
bool B[MAXN];
vector<int> v[MAXN];
vector<pll> seg;
pll ans[MAXN];

bool cmp(pll e1, pll e2) {
	return e1.Y < e2.Y;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n * k; i++) {
		int c;
		cin >> c;
		v[c].push_back(i);
		A[i] = c;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < k - 1; j++)
			seg.push_back({v[i][j], v[i][j + 1]});
	sort(all(seg), cmp);

	int c = (n + k - 2) / (k - 1);
	for (pll e : seg) {
		if (B[A[e.X]]) continue;
		bool flag = true;
		for (int i = e.X; i <= e.Y; i++)
			if (T[i] >= c)
				flag = false;
		if (flag) {
			B[A[e.X]] = true;
			ans[A[e.X]] = e;
			for (int i = e.X; i <= e.Y; i++)
				T[i]++;
		}
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i].X << sep << ans[i].Y << endl;
	return 0;
}