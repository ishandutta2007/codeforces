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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n;
vector<pll> seg;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;

	int prv = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x != prv && cnt > 0) {
			seg.push_back({prv, min(cnt, 2)});
			cnt = 0;
		}

		cnt++;
		prv = x;
	}

	seg.push_back({prv, min(cnt, 2)});		
	int lst = -1, ans = 0;
	for (int i = 0; i < seg.size(); i++) {
		pll e = seg[i];
		ans += e.Y;
		if (e.Y == 2) {
			if (lst < 0) {
				lst = i;
				continue;
			} 
			
			if (e.X == seg[lst].X) {
				bool flag = false;
				set<int> L;
				for (int j = lst + 2; j < i - 1; j++) {
					if (seg[j].X != seg[lst].X) L.insert(seg[j - 1].X);
					if (seg[j].X != seg[i].X) { 
						for (int e : L) {
							if (e != seg[j + 1].X) {
								flag = true;
								break;	
							}
						}
					}

					if (flag) break;
				}

				for (int j = lst + 1; j < i; j++)
					if (seg[lst].X != seg[j + 1].X && seg[j].X != seg[i].X) flag = true;
				for (int j = i - 1; j > lst; j--) 
					if (seg[j - 1].X != seg[i].X && seg[j].X != seg[lst].X) flag = true;
				if (!flag) ans--;
			}

			lst = i;
		}
	}

	cout << ans << endl;
	return 0;
}