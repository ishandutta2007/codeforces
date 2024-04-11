#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define mp make_pair

int n;
ll a;
const int maxn = 300010;
ll nums[maxn];
ll di[maxn];

ll vals[3][maxn*4];  //0 is for total sum, 1 is prefix, 2 is for suffix
set<pii> ranges;
map<pii, int> spot;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> a;
	int ct = 0;
	ll ans = 0;
	vector<pli> stuff;
	for (int i = 1; i <= n; i++) {
		cin >> di[i] >> nums[i];
		nums[i] = a  - nums[i];
		ct++;
		spot[pii(i, i)] = ct;
		ranges.insert(pii(i, i));
		vals[0][ct] = nums[i];
		vals[1][ct] = max(0LL, nums[i]);
		vals[2][ct] = max(0LL, nums[i]);
		ans = max(ans, nums[i]);
		if (i > 1) {
			stuff.push_back(mp(di[i] - di[i-1], i));
		}

		// cout << i << " :: " << vals[0][ct] << " " << vals[1][ct] << 
			// " " << vals[2][ct] << endl;
	}
	
	ll cg = 0;
	sort(stuff.begin(), stuff.end());
	for (pli vp : stuff) {
		cg = vp.first * vp.first;
		int indo = vp.second;

		// cout << "   PROC " << indo  << " " << cg << endl;

		auto it = ranges.lower_bound(pii(indo, indo));
		pii ri = *it;

		--it;
		pii le = *it;

		assert(le.second + 1 == ri.first); //never returning false

		int rind = spot[ri];
		int lind = spot[le];

		it = ranges.erase(it);
		ranges.erase(it);

		ct++;
		ranges.insert(mp(le.first, ri.second));
		spot[mp(le.first, ri.second)] = ct;

		vals[0][ct] = vals[0][rind] + vals[0][lind];
		// vals[0][ct] = max(vals[0][ct], vals[1][rind] + vals[2][lind]);
		vals[1][ct] = max(vals[1][lind], vals[0][lind] + vals[1][rind]);
		vals[2][ct] = max(vals[2][rind], vals[0][rind] + vals[2][lind]);

		// cout << le.first << " to " << ri.second << " : " << vals[0][ct] << " " << 
		// 	vals[1][ct] << " " << vals[2][ct] << endl;

		ans = max(ans, vals[1][rind] + vals[2][lind] - cg);
	}

	cout << ans << endl;
}