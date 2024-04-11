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

int n;
vector<pll> points;

void smth(int l = 0, int r = points.size() - 1) {
	if (l >= r) return;

	int mid = (l + r) >> 1;
	smth(l, mid - 1);
	smth(mid + 1, r);

	for (int i = l; i <= r; i++)
		points.push_back({points[mid].X, points[i].Y});
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		points.push_back({x, y});
	}

	sort(all(points));
	smth();

	sort(all(points));
	vector<pll> ans;
	for (int i = 0; i < points.size(); i++)
		if (i == 0 || points[i] != points[i - 1])
			ans.push_back(points[i]);

	cout << ans.size() << endl;
	for (pll e : ans)
		cout << e.X << sep << e.Y << endl;
	return 0;
}